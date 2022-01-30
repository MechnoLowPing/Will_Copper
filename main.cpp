/***********************************************************************
*
* Copyright (c) 2021-2022 Barbara Geller and Ansel Sermersheim
*
* This example is free software, released under the BSD 2-Clause license.
* For license details refer to LICENSE provided with this project.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://opensource.org/licenses/BSD-2-Clause
*
***********************************************************************/


#include <QtCore>
#include <QtGui>



int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget *mainWindow = new QWidget();
   mainWindow->setMinimumSize(700, 350);
   
   

   QPushButton *pb_1 = new QPushButton();
   pb_1->setText("Close");
   
   

   QSlider *slide_1 = new QSlider();
   slide_1->setRange(0,100);
   slide_1->setOrientation(Qt::Orientation(0x1));

   QSpinBox *spin_1 = new QSpinBox();
   spin_1->setRange(0,100);

   QProgressBar *bar_1 = new QProgressBar();
   bar_1->setRange(0,100);
      

  
   QHBoxLayout *layout_1 = new QHBoxLayout();
   layout_1->addStretch();
   layout_1->addWidget(spin_1);
   layout_1->addSpacing(10);
   layout_1->addWidget(bar_1);
   layout_1->addStretch();

   QHBoxLayout *layout_2 = new QHBoxLayout();
   layout_2->addStretch();
   layout_2->addWidget(slide_1);
   layout_2->addSpacing(10);
   layout_2->addStretch();
   
   QVBoxLayout *layout_main = new QVBoxLayout(mainWindow);
   layout_main->addStretch();
   layout_main->addLayout(layout_1);
   layout_main->addSpacing(10);
   layout_main->addLayout(layout_2);
   layout_main->addSpacing(70);
   layout_main->addWidget(pb_1);
   layout_main->addStretch();
   
   
   QObject::connect(pb_1, &QPushButton::clicked, mainWindow, &QWidget::close);
   QObject::connect(spin_1, cs_mp_cast<int>(&QSpinBox::valueChanged), bar_1, &QProgressBar::setValue);
   QObject::connect(bar_1, cs_mp_cast<int>(&QProgressBar::valueChanged), slide_1, &QSlider::setValue);
   QObject::connect(slide_1, cs_mp_cast<int>(&QSlider::valueChanged), spin_1, &QSpinBox::setValue);
   
   
   mainWindow->show();

   return app.exec();
}