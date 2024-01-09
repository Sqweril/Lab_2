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
	int exp; //какой год службы на военной кафедре
};


typedef struct Voenk // client
{
	PersData persdata;
	int kotegor; // от 1 до 4
	int otsroch; // от 1 до 2
};


typedef struct Solder // less
{
	Voenk voenk;
	Vkaf vkaf;
	char* data; // когда должен явиться в военк
	char* time;
	int status; // годен или нет
};



//функции по инициализация всех структур

SNILS* CreateSNILS(int number, int pol) {
	if (number > 0 && pol > 0 && pol < 3) {
		SNILS* snils = (SNILS*)calloc(1, sizeof(SNILS));
		snils->number = number;
		snils->pol = pol;
		return snils;
	}
	else {
		printf("1Неправильный ввод данных данных!");
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
		printf("2Неправильный ввод данных данных!");
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
		printf("3Неправильный ввод данных данных!");
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
		printf("4Неправильный ввод данных данных!");
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
		printf("5Неправильный ввод данных данных!");
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
		printf("6Неправильный ввод данных данных!");
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
		printf("7Неправильный ввод данных данных!");
		exit(EXIT_SUCCESS);
	}
}

//функции по вводу структур

SNILS* InputSNILS() {
	printf("\tВвод СНИЛСа\n");

	int number;
	long long int pol;

	printf("Введите номер СНИЛа: ");
	scanf("%d", &number);
	printf("Введите пол (1-мужской, 2- женский): ");
	scanf("%d", &pol);
	while (getchar() != '\n');
	return CreateSNILS(number, pol);
}

Pasport* InputPasprt() {
	printf("\tВвод паспорта\n");

	int seria;
	int number;

	printf("Введите серию: ");
	scanf("%d", &seria);
	printf("Введите номер: ");
	scanf("%d", &number);
	while (getchar() != '\n');
	return CreatePasport(seria, number);
}

Docs* InputDocs() {
	printf("\tВвод документов\n");
	return CreateDocs(*InputSNILS(), *InputPasprt());
}

PersData* InputPersData() {
	printf("\tВвод персональных данных\n");

	int age;
	char* fio = (char*)calloc(40, sizeof(char));

	printf("Введите возраст: ");
	scanf("%d", &age);
	printf("Введите ФИО: ");
	while (getchar() != '\n');
	gets_s(fio, 40);
	return CreatePersData(*InputDocs(), age, fio);
}

Vus* InputVus() {
	printf("\tВвод параметров Учебного заведения\n");

	char* name = (char*)calloc(50, sizeof(char));
	char* fakul = (char*)calloc(50, sizeof(char));
	int kurse;
	char* naprav = (char*)calloc(50, sizeof(char));

	printf("Введите название уч.завед: ");
	gets_s(name, 50);
	printf("Введите название факультета: ");
	gets_s(fakul, 50);
	printf("Введите курс обучения: ");
	scanf("%d", &kurse);
	printf("Введите название направления: ");
	while (getchar() != '\n');
	gets_s(naprav, 50);
	return CreateVus(name, fakul, kurse, naprav);
}

Vkaf* InputVkaf() {
	printf("\tВвод данных с военного учёта уч.завед\n");


	int exp;

	printf("Введите какой срок службы на военной кафедре: ");
	scanf("%d", &exp);
	while (getchar() != '\n');
	return CreateVkaf(*InputVus(), *InputPersData(), exp);
}

Voenk* InputVoenk() {
	printf("\tВвод данных военкомата\n");


	int kotegor;
	int otsroch;

	printf("Введите категорию: ");
	scanf("%d", &kotegor);
	printf("Введите (1 - есть отсрочка, 2 - нет отсрочки): ");
	scanf("%d", &otsroch);
	while (getchar() != '\n');
	return CreateVoenk(*InputPersData(), kotegor, otsroch);
}

Solder* InputSolder() {
	printf("\tВвод Солдата\n");

	char* data = (char*)calloc(40, sizeof(char));
	char* time = (char*)calloc(40, sizeof(char));
	int status;

	printf("Введите дату явки в военкомат: ");
	gets_s(data, 40);
	printf("Введите время явки в военкомат: ");
	gets_s(time, 40);
	printf("Введите (1 - годен к службе, 2 - не годен): ");
	scanf("%d", &status);
	while (getchar() != '\n');
	return CreateSolder(*InputVoenk(), *InputVkaf(), data, time, status);
}

void PrintVkaf(Vkaf vkaf) {
	printf("\tИфнормация о студенте в военном учётном центре в уч. зав.\n");
	printf("ФИО - %s, Возраст - %d\n", vkaf.persdata.fio, vkaf.persdata.age);
	printf("Документы: Паспорт - %d %d, СНИЛС - %d\n", vkaf.persdata.docs.pasport.seria, vkaf.persdata.docs.pasport.nomer, vkaf.persdata.docs.snils.number);
	printf("Учеб.заведение: Название - %s, Факультет - %s, Направление - %s, Курс- %d\n", vkaf.vus.name, vkaf.vus.fakul, vkaf.vus.naprav, vkaf.vus.kurse);
}

void PrintSolder(Solder solder) {
	printf("\tИнформация о призывнике\n");
	printf("Дата явки в военкомат - %s, Время явки в военкомат- %s, (1-годен, 2-не годен) - %d\n", solder.data, solder.time, solder.status);
}

void PrintVoenk(Voenk voenk) {
	printf("\tИфнормация о призывнике в военкомате\n");
	printf("ФИО - %s, Возраст - %d\n", voenk.persdata.fio, voenk.persdata.age);
	printf("Документы: Паспорт - %d %d, СНИЛС - %d\n", voenk.persdata.docs.pasport.seria, voenk.persdata.docs.pasport.nomer, voenk.persdata.docs.snils.number);
}

//изменение статуса оплаты урока
void ChangeStatus(Solder* solder, int newStatus) {
	if (newStatus > 0 && newStatus < 3) {
		solder->status = newStatus;
		printf("Статус призывника успешно изменён\n");
	}
	else {
		printf("Неправильный формат данных!");
		exit(EXIT_SUCCESS);
	}
}
//освобождение памяти для объектов внутри Lesson
void FreeSolderMemory(Solder* solder) {
	free(solder->data);
	free(solder->time);
	free(solder->vkaf.persdata.fio);
	free(solder->vkaf.vus.name);
	free(solder->vkaf.vus.fakul);
	free(solder->vkaf.vus.naprav);
	free(solder->voenk.persdata.fio);
}