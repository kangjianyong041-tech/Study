#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string> 
#define MAX 1000  
using namespace std;

void addPerson();
void showPerson();
void deletePerson();
void deletePerson();
void deletePerson();

//联系人结构体
struct Person {
	string m_name;//姓名
	int m_sex;//性别1.女2.男
	int m_age;//年龄
	string m_phone;//手机号
	string m_addr;//地址
};
struct Addressbooks {
	struct Person personArray[MAX];//通讯录中保存的联系人数组
	int m_size;//通讯录中人员的个数
};
void addPerson(Addressbooks* abs) {
	//判断通讯录是否已满
	if (abs->m_size == MAX) {
		cout<< "通讯录已满，无法添加!" << endl;
		return;
	}
	else {
		//添加具体联系人
		string name;
		cout << "请输入姓名: ";
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;
		int sex = 0;
		cout << "请输入性别(1.女 2.男): ";
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			else {
				cout << "输入有误，请重新输入性别(1.女 2.男): ";
			}
		}
		int age = 0;
		cout << "请输入年龄: ";
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;
		string phone;
		cout << "请输入电话: ";
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;
		string addr;
		cout << "请输入地址: ";
		cin >> addr;
		abs->personArray[abs->m_size].m_addr = addr;
		//更新通讯录人数
		abs->m_size++;

		cout << "添加成功!" << endl;

		system("pause");
		system("cls");

	}  
}
void showPerson(Addressbooks* abs) {
	if (abs->m_size == 0) {
		cout << "通讯录为空!" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "姓名: " << abs->personArray[i].m_name << "\t";
			cout << "性别: " << (abs->personArray[i].m_sex == 1 ? "女" : "男") << "\t";
			cout << "年龄: " << abs->personArray[i].m_age << "\t";
			cout << "电话: " << abs->personArray[i].m_phone << "\t";
			cout << "地址: " << abs->personArray[i].m_addr << endl;
		}
	}
}
	void deletePerson(Addressbooks * abs) {
		if (abs->m_size == 0) {
			cout << "通讯录为空!" << endl;
			return;
		}
		else {
			string name;
			cout << "请输入要删除的联系人姓名: ";
			cin >> name;
			int index = -1;
			for (int i = 0; i < abs->m_size; i++) {
				if (abs->personArray[i].m_name == name) {
					index = i;
					break;
				}
			}
			if (index == -1) {
				cout << "未找到联系人!" << endl;
				return;
			}
			else {
				for (int i = index; i < abs->m_size - 1; i++) {
					abs->personArray[i] = abs->personArray[i + 1];
				}
				abs->m_size--;
				cout << "删除成功!" << endl;
				return;
			}
		}
	}
	void findPerson(Addressbooks* abs) {
		if (abs->m_size == 0) {
			cout << "通讯录为空!" << endl;
			return;
		}
		else {
			string name;
			cout << "请输入要查找的联系人姓名: ";
			cin >> name;
			int index = -1;
			for (int i = 0; i < abs->m_size; i++) {
				if (abs->personArray[i].m_name == name) {
					index = i;
					break;
				}
			}
			if (index == -1) {
				cout << "未找到联系人!" << endl;
				return;
			}
			else {
				cout << "姓名: " << abs->personArray[index].m_name << "\t";
				cout << "性别: " << (abs->personArray[index].m_sex == 1 ? "女" : "男") << "\t";
				cout << "年龄: " << abs->personArray[index].m_age << "\t";
				cout << "电话: " << abs->personArray[index].m_phone << "\t";
				cout << "地址: " << abs->personArray[index].m_addr << endl;
				return;
			}
		}
	}

	void alterPerson(Addressbooks* abs) {
		if (abs->m_size == 0) {
			cout << "通讯录为空!" << endl;
			return;
		}
		else {
			string name;
			cout << "请输入要修改的联系人姓名: ";
			cin >> name;
			int index = -1;
			for (int i = 0; i < abs->m_size; i++) {
				if (abs->personArray[i].m_name == name) {
					index = i;
					break;
				}
			}
			if (index == -1) {
				cout << "未找到联系人!" << endl;
				return;
			}
			else {
				cout << "请输入新的姓名: ";
				cin >> abs->personArray[index].m_name;
				int sex = 0;
				cout << "请输入新的性别(1.女 2.男): ";
				while (true) {
					cin >> sex;
					if (sex == 1 || sex == 2) {
						abs->personArray[index].m_sex = sex;
						break;
					}
					else {
						cout << "输入有误，请重新输入性别(1.女 2.男): ";
					}
				}
				int age = 0;
				cout << "请输入新的年龄: ";
				cin >> age;
				abs->personArray[index].m_age = age;
				string phone;
				cout << "请输入新的电话: ";
				cin >> phone;
				abs->personArray[index].m_phone = phone;
				string addr;
				cout << "请输入新的地址: ";
				cin >> addr;
				abs->personArray[index].m_addr = addr;
				cout << "修改成功!" << endl;
				system("pause");
				system("cls");
			}
		}
	}
	void clearPerson(Addressbooks* abs) {
		if (abs->m_size == 0) {
			cout << "通讯录为空!" << endl;
			return;
		}
		else {
			abs->m_size = 0;
			cout << "清空成功!" << endl;
			return;
		}
	}

	void quitPerson(Addressbooks* abs) {
		cout << "退出成功!" << endl;
		return;
	}
void showMenu(){
	cout << "*************************" << endl;
	cout << "***** 1, 添加联系人 *****" << endl;
	cout << "***** 2, 显示联系人 *****" << endl;
	cout << "***** 3, 删除联系人 *****" << endl;
	cout << "***** 4, 查找联系人 *****" << endl;
	cout << "***** 5, 修改联系人 *****" << endl;
	cout << "***** 6, 清空联系人 *****" << endl;
	cout << "***** 0, 退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录人数
	abs.m_size = 0;
	int select = 0;
	while (true) {
		showMenu();
		cout << "请选择功能: ";
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);//利用地址传递，可以修饰实参
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			alterPerson(&abs);
			break;
		case 6:
			clearPerson(&abs);
			break;
		case 0:
			quitPerson(&abs);
			return 0;
		default:
			cout << "输入有误，请重新输入!" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
	}
	
