#include<iostream>
using namespace std;

//展示菜单
void showMenu()
{
	cout << "1.添加联系人\n2.显示联系人\n3.删除联系人\n4.查找联系人\n5.修改联系人\n6.清空联系人\n0.退出通讯录" << endl;

}

int main()
{
	int select = 0;

	showMenu();

	cin >> select;

	switch (select)
	{
	case 0://退出通讯录
		cout << "欢迎下次使用通讯录系统，按任意键退出" << endl;
		break;
	case 1://添加联系人
		break;
	case 2://显示联系人
		break;
	case 3://删除联系人
		break;
	case 4://查找联系人
		break;
	case 5://修改联系人
		break;
	case 6://清空联系人
		break;
	default:
		break;
	}

	system("pause");
	return 0;
}