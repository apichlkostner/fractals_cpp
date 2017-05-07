// Calculation of julia set
// Copyright (C) 2017  <name of author>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <memory>
#include <iostream>
#include <QImage>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "juliaset.h"

using namespace std;
using namespace fractals;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene* scene = new QGraphicsScene(this);
    pmi = new QGraphicsPixmapItem();    

    scene->addItem(pmi);

    ui->fractalView->setScene(scene);
    ui->progressBar->setValue(0);

    // calculate color map
    for (auto i = 0; i < 256; i++) {
        int r = (20 * i) % 255;
        int g = (40 * i) % 255;
        int b = (60 * i) % 255;
        colors.push_back(QColor(r, g, b));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calcButton_clicked()
{
    unique_ptr<JuliaSet> js(new JuliaSet());
    JuliaSet myjs();
    const auto lx = ui->fractalView->contentsRect().width();
    const auto ly = ui->fractalView->contentsRect().height();

    // calculate julia set
    vector<vector<int>> intpicture = js->calc(complex<double>(0, 0), 1.0, vector<int>({lx, ly}));

    QImage juliaImage(lx, ly, QImage::Format_RGB32);

    // render julia set
    for (auto h = 0; h < lx; h++) {
        ui->progressBar->setValue((h + 1) *100 / ly);
        for (auto v = 0; v < ly; v++){
            int val = intpicture[h][v] % 256;
            QColor fc = colors[val];
            juliaImage.setPixelColor(h, v, fc);
        }
    }

    pmi->setPixmap(QPixmap::fromImage(juliaImage));
}

