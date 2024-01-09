#pragma once
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>



typedef struct Pasport //id
{
	int seria;
	int nomer;
};


typedef struct SNILS  
{
	long long int number;
	int pol;
};


typedef struct Docs 
{
	SNILS snils;
	Pasport pasport;
};


typedef struct PersData
{
	Docs docs;
	int age;
	char* fio;
};

typedef struct Vus // auto
{
	char* name;
	char* fakul;
	int kurse;
	char* naprav;
};


typedef struct Vkaf // instuk
{
	Vus vus;
	PersData persdata;
	int exp; //����� ��� ������ �� ������� �������
};


typedef struct Voenk // client
{
	PersData persdata;
	int kotegor; // �� 1 �� 4
	int otsroch; // �� 1 �� 2
};


typedef struct Solder // less
{
	Voenk voenk;
	Vkaf vkaf;
	char* data; // ����� ������ ������� � �����
	char* time;
	int status; // ����� ��� ���
};



//������� �� ������������� ���� ��������

SNILS* CreateSNILS(int number, int pol) {
	if (number > 0 && pol > 0 && pol < 3) {
		SNILS* snils = (SNILS*)calloc(1, sizeof(SNILS));
		snils->number = number;
		snils->pol = pol;
		return snils;
	}
	else {
		printf("1������������ ���� ������ ������!");
		exit(EXIT_SUCCESS);
	}
}

Pasport* CreatePasport(int seria, int nomer) {
	if (nomer > 0 && seria > 0) {
		Pasport* pasport = (Pasport*)calloc(1, sizeof(Pasport));
		pasport->nomer = nomer;
		pasport->seria = seria;
		return pasport;
	}
	else {
		printf("2������������ ���� ������ ������!");
		exit(EXIT_SUCCESS);
	}
}

Docs* CreateDocs(SNILS snils, Pasport pasport) {
	Docs* docs = (Docs*)calloc(1, sizeof(Docs));
	docs->snils = snils;
	docs->pasport= pasport;
	return docs;
}

PersData* CreatePersData(Docs docs, int age, char* fio) {
	if (age > 0 && strlen(fio) != 0) {
		PersData* persdata = (PersData*)calloc(1, sizeof(PersData));
		persdata->fio = (char*)calloc(40, sizeof(char));
		strcpy(persdata->fio, fio);
		persdata->docs = docs;
		persdata->age = age;
		return persdata;
	}
	else {
		printf("3������������ ���� ������ ������!");
		exit(EXIT_SUCCESS);
	}
}

Vus* CreateVus(char* name, char* fakul, int kurse, char* naprav) {
	if (strlen(name) != 0 && strlen(fakul) != 0 && strlen(naprav) != 0 && kurse > 0 && kurse < 5) {
		Vus* vus = (Vus*)calloc(1, sizeof(Vus));
		vus-> name= (char*)calloc(50, sizeof(char));
		vus-> fakul= (char*)calloc(50, sizeof(char));
		vus-> naprav= (char*)calloc(50, sizeof(char));
		strcpy(vus->name, name);
		strcpy(vus->fakul, fakul);
		strcpy(vus->naprav, naprav);
		vus-> kurse = kurse;
		return vus;
	}
	else {
		printf("4������������ ���� ������ ������!");
		exit(EXIT_SUCCESS);
	}
}

Vkaf* CreateVkaf(Vus vus, PersData persdata, int exp) {
	if (exp > 0 && exp < 4) {
		Vkaf* vkaf = (Vkaf*)calloc(1, sizeof(Vkaf));
		vkaf->vus = vus;
		vkaf->persdata = persdata;
		vkaf-> exp = exp;
		return vkaf;
	}
	else {
		printf("5������������ ���� ������ ������!");
		exit(EXIT_SUCCESS);
	}
}

Voenk* CreateVoenk(PersData persdata, int kotegor, int otsroch) {
	if (kotegor > 0 && kotegor < 5 && otsroch > 0 && otsroch < 3) {
		Voenk* voenk = (Voenk*)calloc(1, sizeof(Voenk));
		voenk->persdata = persdata;
		voenk->kotegor = kotegor;
		voenk-> otsroch = otsroch;
		return voenk;
	}
	else {
		printf("6������������ ���� ������ ������!");
		exit(EXIT_SUCCESS);
	}
}

Solder* CreateSolder(Voenk voenk, Vkaf vkaf, char* data, char* time, int status) {
	if (strlen(data) != 0 && strlen(time) != 0 && status > 0 && status < 3) {
		Solder* solder = (Solder*)calloc(1, sizeof(Solder));
		solder->voenk = voenk;
		solder->vkaf = vkaf;
		solder->data = (char*)calloc(40, sizeof(char));
		solder->time = (char*)calloc(40, sizeof(char));
		strcpy(solder->data, data);
		strcpy(solder->time, time);
		solder->status = status;
		return solder;
	}
	else {
		printf("7������������ ���� ������ ������!");
		exit(EXIT_SUCCESS);
	}
}

//������� �� ����� ��������

SNILS* InputSNILS() {
	printf("\t���� ������\n");

	int number;
	long long int pol;

	printf("������� ����� �����: ");
	scanf("%d", &number);
	printf("������� ��� (1-�������, 2- �������): ");
	scanf("%d", &pol);
	while (getchar() != '\n');
	return CreateSNILS(number, pol);
}

Pasport* InputPasprt() {
	printf("\t���� ��������\n");

	int seria;
	int number;

	printf("������� �����: ");
	scanf("%d", &seria);
	printf("������� �����: ");
	scanf("%d", &number);
	while (getchar() != '\n');
	return CreatePasport(seria, number);
}

Docs* InputDocs() {
	printf("\t���� ����������\n");
	return CreateDocs(*InputSNILS(), *InputPasprt());
}

PersData* InputPersData() {
	printf("\t���� ������������ ������\n");

	int age;
	char* fio = (char*)calloc(40, sizeof(char));

	printf("������� �������: ");
	scanf("%d", &age);
	printf("������� ���: ");
	while (getchar() != '\n');
	gets_s(fio, 40);
	return CreatePersData(*InputDocs(), age, fio);
}

Vus* InputVus() {
	printf("\t���� ���������� �������� ���������\n");

	char* name = (char*)calloc(50, sizeof(char));
	char* fakul = (char*)calloc(50, sizeof(char));
	int kurse;
	char* naprav = (char*)calloc(50, sizeof(char));

	printf("������� �������� ��.�����: ");
	gets_s(name, 50);
	printf("������� �������� ����������: ");
	gets_s(fakul, 50);
	printf("������� ���� ��������: ");
	scanf("%d", &kurse);
	printf("������� �������� �����������: ");
	while (getchar() != '\n');
	gets_s(naprav, 50);
	return CreateVus(name, fakul, kurse, naprav);
}

Vkaf* InputVkaf() {
	printf("\t���� ������ � �������� ����� ��.�����\n");


	int exp;

	printf("������� ����� ���� ������ �� ������� �������: ");
	scanf("%d", &exp);
	while (getchar() != '\n');
	return CreateVkaf(*InputVus(), *InputPersData(), exp);
}

Voenk* InputVoenk() {
	printf("\t���� ������ ����������\n");


	int kotegor;
	int otsroch;

	printf("������� ���������: ");
	scanf("%d", &kotegor);
	printf("������� (1 - ���� ��������, 2 - ��� ��������): ");
	scanf("%d", &otsroch);
	while (getchar() != '\n');
	return CreateVoenk(*InputPersData(), kotegor, otsroch);
}

Solder* InputSolder() {
	printf("\t���� �������\n");

	char* data = (char*)calloc(40, sizeof(char));
	char* time = (char*)calloc(40, sizeof(char));
	int status;

	printf("������� ���� ���� � ���������: ");
	gets_s(data, 40);
	printf("������� ����� ���� � ���������: ");
	gets_s(time, 40);
	printf("������� (1 - ����� � ������, 2 - �� �����): ");
	scanf("%d", &status);
	while (getchar() != '\n');
	return CreateSolder(*InputVoenk(), *InputVkaf(), data, time, status);
}

void PrintVkaf(Vkaf vkaf) {
	printf("\t���������� � �������� � ������� ������� ������ � ��. ���.\n");
	printf("��� - %s, ������� - %d\n", vkaf.persdata.fio, vkaf.persdata.age);
	printf("���������: ������� - %d %d, ����� - %d\n", vkaf.persdata.docs.pasport.seria, vkaf.persdata.docs.pasport.nomer, vkaf.persdata.docs.snils.number);
	printf("����.���������: �������� - %s, ��������� - %s, ����������� - %s, ����- %d\n", vkaf.vus.name, vkaf.vus.fakul, vkaf.vus.naprav, vkaf.vus.kurse);
}

void PrintSolder(Solder solder) {
	printf("\t���������� � ����������\n");
	printf("���� ���� � ��������� - %s, ����� ���� � ���������- %s, (1-�����, 2-�� �����) - %d\n", solder.data, solder.time, solder.status);
}

void PrintVoenk(Voenk voenk) {
	printf("\t���������� � ���������� � ����������\n");
	printf("��� - %s, ������� - %d\n", voenk.persdata.fio, voenk.persdata.age);
	printf("���������: ������� - %d %d, ����� - %d\n", voenk.persdata.docs.pasport.seria, voenk.persdata.docs.pasport.nomer, voenk.persdata.docs.snils.number);
}

//��������� ������� ������ �����
void ChangeStatus(Solder* solder, int newStatus) {
	if (newStatus > 0 && newStatus < 3) {
		solder->status = newStatus;
		printf("������ ���������� ������� ������\n");
	}
	else {
		printf("������������ ������ ������!");
		exit(EXIT_SUCCESS);
	}
}
//������������ ������ ��� �������� ������ Lesson
void FreeSolderMemory(Solder* solder) {
	free(solder->data);
	free(solder->time);
	free(solder->vkaf.persdata.fio);
	free(solder->vkaf.vus.name);
	free(solder->vkaf.vus.fakul);
	free(solder->vkaf.vus.naprav);
	free(solder->voenk.persdata.fio);
}