#include<iostream>
#include<string>
using namespace std;

#define MAX 10000

//联系人结构体
struct Person
{
	string m_Name;//姓名
	int m_Sex;//性别
	int m_Age;//年龄
	string phoneNumber;//电话
	string m_Addr;//地址
};

//通讯录结构体
struct Addressbooks
{
	//联系人数组
	struct Person personArray[MAX];
	//当前记录联系人的数量
	int m_Size;
};

//查找联系人
int search(Addressbooks* abs, string name)
{
	int i = 0;
	for (; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name) break;
	}
	if (i == abs->m_Size) return -1;
	return i;
}

//添加联系人
void AddPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		//姓名输入
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别输入
		int sex;
		cout << "请输入性别\n1 - - 男\n0 - - 女\n若不记录性别则输入-1" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2||sex== -1)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "请输入正确的性别\n1  - -  男\n0 - - 女\n若不记录性别则输入-1" << endl;
		}

		//年龄输入
		int age = 0;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话输入
		string phone;
		cout << "请输入电话号码" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].phoneNumber = phone;

		//住址输入
		string address;
		cout << "请输入住址" << endl;
		cin>>address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;
	}
}

//打印一个联系人
void printPerson(struct Person person)
{
	cout << "姓名: " << person.m_Name << endl;
	if(person.m_Sex==1)
		cout << "性别：男" << endl;
	else if(person.m_Sex==0)
		cout << "性别：女" << endl;
	else 
		cout << "性别：不明" << endl;
	cout << "年龄：" << person.m_Age << endl;
	cout << "电话号：" << person.phoneNumber << endl;
	cout << "住址：" << person.m_Addr << endl;
}

//展示联系人
void ShowBooks(Addressbooks* abs)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		cout << "No." << i << endl;
		printPerson(abs->personArray[i]);
		cout << endl;
	}
}

//删除联系人
void DeletePerson(Addressbooks* abs)
{
	cout << "请输入要删除的联系人姓名" << endl;
	string name;
	cin >> name;
	int location=search(abs, name);
	if (location == -1)
	{
		cout << "该联系人不存在！" << endl;
		return;
	}
	printPerson(abs->personArray[location]);
	cout << "请问是否确认删除该联系人！\n若确认删除则输入  确认  " << endl;
	string ifDelete;
	cin >> ifDelete;
	if (ifDelete == "确认")
	{
		for (int i = location; i < abs->m_Size-1; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "成功删除联系人" << name << endl;
		return;
	}
}

//修改联系人
void ModifyPerson(Addressbooks* abs)
{
	cout << "请输入要修改的联系人姓名" << endl;
	string name;
	cin >> name;
	int location = search(abs, name);
	if (location == -1)
	{
		cout << "该联系人不存在！" << endl;
		return;
	}
	while (true)
	{
		cout << endl;
		printPerson(abs->personArray[location]);
		cout << "请输入要修改哪一项信息，若不修改请输入  结束" << endl;
		string select;
		cin >> select;
		if (select == "结束") break;
		cout << "请输入要将该信息修改的为什么：" << endl;
		if (select == "姓名" || select == "地址" || select == "电话号")
		{
			string change;
			cin >> change;
			if (select == "姓名")
			{
				abs->personArray[location].m_Name = change;
			}
			else if (select == "地址")
			{
				abs->personArray[location].m_Addr = change;
			}
			else
			{
				abs->personArray[location].phoneNumber = change;
			}
			cout << "修改成功!" << endl;
		}
	}
}

//展示菜单
void showMenu()
{
	cout << "1.添加联系人\n2.显示联系人\n3.删除联系人\n4.查找联系人\n5.修改联系人\n6.清空联系人\n0.退出通讯录" << endl;
}

int main()
{
	//初始化通讯录
	Addressbooks abs;
	abs.m_Size = 0;

	int select = 0;

	showMenu();
	while (true)
	{
		cout << "\n请输入操作" << endl;
		cin >> select;
		if (select == 0)//退出通讯录
		{
			cout << "欢迎下次使用通讯录系统，按任意键退出" << endl;
			break;
		}
		switch (select)
		{
		case 1://添加联系人
			AddPerson(&abs);
			break;
		case 2://显示联系人
			ShowBooks(&abs);
			break;
		case 3://删除联系人
			DeletePerson(&abs);
			break;
		case 4://查找联系人
			{
				string name;
				cout << "请输入要查找的人的姓名" << endl;
				cin >> name;
				int location = search(&abs, name);
				if (location == -1) cout << "该联系人不存在！" << endl;
				else printPerson(abs.personArray[location]);
				break; 
			}
		case 5://修改联系人
			ModifyPerson(&abs);
			break;
		case 6://清空联系人
			abs.m_Size = 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}