#include "mondossierframe.h"
#include "ui_dossierrejeteframe.h"
#include <QStandardItemModel>

Dossierrejeteframe::Dossierrejeteframe(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Dossierrejeteframe)
{
    ui->setupUi(this);
    DossierManager manager;
    QList<Dossier> l = manager.all_non_valide();
    QStringList header;
    header << "Numero Dossier" << "Nom" << "Prénom" << "Acte de naissance" << "CV" << "Photo" << "Diplôme" << "Statut";
    QStandardItemModel *model= new QStandardItemModel(l.size(),8,this);
            model->setHorizontalHeaderLabels(header);
            ui->table_dossiers_rejetes->setModel(model);
            ui->table_dossiers_rejetes->horizontalHeader()->setStretchLastSection(true);
            ui->table_dossiers_rejetes->resizeRowsToContents();
            ui->table_dossiers_rejetes->verticalHeader()->hide();
            ui->table_dossiers_rejetes->setSortingEnabled(false);
            ui->table_dossiers_rejetes->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->table_dossiers_rejetes->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->table_dossiers_rejetes->setSelectionMode(QAbstractItemView::SingleSelection);
            for(int i=0;i < l.size();i++){
                QString num = QString::number(l.at(i).id());
                QStandardItem * id= new QStandardItem(num);
                QStringList lcv = l.at(i).cv().split("/");
                QStandardItem * cv= new QStandardItem(lcv.at(lcv.size()-1));
                QStringList lphoto = l.at(i).photo().split("/");
                QStandardItem * photo= new QStandardItem(lphoto.at(lphoto.size()-1));
                QStringList ldip = l.at(i).diplome().split("/");
                QStandardItem * diplome= new QStandardItem(ldip.at(ldip.size()-1));
                QStringList lacte = l.at(i).acte_naissance().split("/");
                QStandardItem * acte_naissance= new QStandardItem(lacte.at(lacte.size()-1));
                Candidature candidature = l.at(i).candidature();
                Candidat candidat = candidature.candidat();
                QStandardItem * nom= new QStandardItem(candidat.nom());
                QStandardItem * prenom= new QStandardItem(candidat.prenom());
                QStandardItem * statut= new QStandardItem("Rejeté");
                model->setItem(i,0,id);
                model->setItem(i,1,nom);
                model->setItem(i,2,prenom);
                model->setItem(i,3,acte_naissance);
                model->setItem(i,4,cv);
                model->setItem(i,5,photo);
                model->setItem(i,6,diplome);
                model->setItem(i,7,statut);
                ui->table_dossiers_rejetes->resizeRowsToContents();
                ui->table_dossiers_rejetes->resizeColumnsToContents();
            }

}

Dossierrejeteframe::~Dossierrejeteframe()
{
    delete ui;
}
