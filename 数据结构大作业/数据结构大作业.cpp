// 数据结构大作业.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<stdlib.h>
#define	maxsize	5000

using	namespace std;

struct Word
{
	string	w="";
	int num=0;
};

struct SqList//顺序表
{
	Word	*elem;
	int len=0;
};

typedef	struct LNode//链表
{
	Word	data;
	struct LNode	*next;
}LNode,*LinkList;

typedef	struct BSTNode
{
	Word	data;
	struct BSTNode	*lchild, *rchild;
}BSTNode,*BSTree;

struct HashTable
{
	int	n=0;//记录出现冲突的次数
	Word	data;
};

typedef	struct //哈希链表
{
	LinkList	L = NULL;
}hash_LNode[maxsize];

void	cover1()
{
	cout << "********************************************************************************" << endl;
	cout << "*********************** 基于不同策略的单词统计和检索系统 ***********************\n" << endl;
	cout << "\n" << endl;
	cout << "1：基于线性表的查找" << endl;
	cout << "2：基于二叉排序树的查找" << endl;
	cout << "3：基于哈希表的查找" << endl;
	cout << "4：退出\n" << endl;
	cout << "请输入相应的数字进行选择：" << endl;
}

void	cover2()
{
	cout << "********************************************************************************" << endl;
	cout << "***********************         基于线性表的查找         ***********************\n" << endl;
	cout << "\n" << endl;
	cout << "1：顺序查找" << endl;
	cout << "2：折半查找" << endl;
	cout << "3：返回上一级\n" << endl;
	cout << "请输入相应的数字进行选择：" << endl;
}

void	cover3()
{
	cout << "********************************************************************************" << endl;
	cout << "***********************             顺序查找             ***********************\n" << endl;
	cout << "\n" << endl;
	cout << "1：基于顺序表的顺序查找" << endl;
	cout << "2：基于链表的顺序查找" << endl;
	cout << "3：返回上一级\n" << endl;
	cout << "请输入相应的数字进行选择：" << endl;
}

void	cover4()
{
	cout << "********************************************************************************" << endl;
	cout << "***********************       基于顺序表的顺序查找       ***********************\n" << endl;
	cout << "\n" << endl;
	cout << "1：词频统计" << endl;
	cout << "2：单词查找" << endl;
	cout << "3：返回上一级\n" << endl;
	cout << "请输入相应的数字进行选择：" << endl;
}

void	cover5()
{
	cout << "********************************************************************************" << endl;
	cout << " ***********************       -----单词查找-----       ***********************\n" << endl;
	cout << "\n" << endl;
}

void	cover6()
{
	cout << "********************************************************************************" << endl;
	cout << "****************************       -折半查找-       ****************************\n" << endl;
	cout << "\n" << endl;
	cout << "1：词频统计" << endl;
	cout << "2：单词查找" << endl;
	cout << "3：返回上一级\n" << endl;
	cout << "请输入相应的数字进行选择：" << endl;
}

void	cover7()
{
	cout << "********************************************************************************" << endl;
	cout << "***********************       -基于链表的顺序查找-       ***********************\n" << endl;
	cout << "\n" << endl;
	cout << "1：词频统计" << endl;
	cout << "2：单词查找" << endl;
	cout << "3：返回上一级\n" << endl;
	cout << "请输入相应的数字进行选择：" << endl;
}

void	cover8()
{
	cout << "********************************************************************************" << endl;
	cout << "***********************       -基于二叉排序树的查找-       *********************\n" << endl;
	cout << "\n" << endl;
	cout << "1：词频统计" << endl;
	cout << "2：单词查找" << endl;
	cout << "3：返回上一级\n" << endl;
	cout << "请输入相应的数字进行选择：" << endl;
}

void	cover9()
{
	cout << "********************************************************************************" << endl;
	cout << "***********************             哈希查找             ***********************\n" << endl;
	cout << "\n" << endl;
	cout << "1：基于开放地址法的哈希查找" << endl;
	cout << "2：基于链地址法的哈希查找" << endl;
	cout << "3：返回上一级\n" << endl;
	cout << "请输入相应的数字进行选择：" << endl;
}

void	cover10()
{
	cout << "********************************************************************************" << endl;
	cout << "*********************       -基于开放地址法的哈希查找-       *******************\n" << endl;
	cout << "\n" << endl;
	cout << "1：词频统计" << endl;
	cout << "2：单词查找" << endl;
	cout << "3：返回上一级\n" << endl;
	cout << "请输入相应的数字进行选择：" << endl;
}

void	cover11()
{
	cout << "********************************************************************************" << endl;
	cout << "*********************       -基于链地址法的哈希查找-       *********************\n" << endl;
	cout << "\n" << endl;
	cout << "1：词频统计" << endl;
	cout << "2：单词查找" << endl;
	cout << "3：返回上一级\n" << endl;
	cout << "请输入相应的数字进行选择：" << endl;
}

void	cover12()
{
	cout << "********************************************************************************\n" << endl;
	cout << "*****************************       -单词查找-       ***************************\n" << endl;
	cout << "\n\n";
}


void	qsort_sqlist(SqList	&jay, int low, int high)//low=0,high=len-1,快排
{
	if (low >= high)//不能写low==high
		return;
	int	i, j;
	i = low;
	j = high;
	Word	key;
	key = jay.elem[i];
	while (i < j)
	{
		while (i < j && (jay.elem[j].w >= key.w))
			j--;
		jay.elem[i] = jay.elem[j];
		while (i < j && (jay.elem[i].w <= key.w))
			i++;
		jay.elem[j] = jay.elem[i];
	}
	jay.elem[i] = key;
	qsort_sqlist(jay, low, i - 1);//递归调用
	qsort_sqlist(jay, i + 1, high);
}

void	input_sqlist(SqList &jay)//顺序表读单词
{
	int	i = 0;//下标
	string s="";//临时存储单词
	char c;//临时存储字母
	ifstream	in;//读文件
	in.open("InFile.txt");//打开文件
	if (!in)
	{
		cout << "can't open this file\n";
		return;
	}
	while (!in.eof())//读取单词
	{
		in.get(c);//用in>>不行
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)||c == '\'')//判断c是否为字母和 '
		{
			if (c <= 90 && c != '\'')//如果是大写字母转换为小写字母
				c = c + 32;
			s = s + c;
		}
		else//成功读取一个单词
		{
			if (s != "")//排除连续出现多个非字母字符的情况
			{
				int flag = 0;//判断该单词是否已存在于顺序表中
				for (int j = 0; j < i; j++)
				{
					if (s == jay.elem[j].w)
					{
						flag = 1;//该单词存在顺序表中
						jay.elem[j].num++;
						break;
					}
				}
				if (flag == 0)
				{
					jay.elem[i].w = s;//将该单词存进顺序表
					jay.elem[i].num++;
					i++;
				}
				s = "";//s清空
			}
		}
	}
	jay.len = i;
	in.close();
}

int	input_LinkList(LinkList &L)//链表读单词
{
	LinkList	r,p;
	int	l ;//记录链表长度
	l = 0;
	string s = "";//临时存储单词
	char c;//临时存储字母
	ifstream	in;//读文件
	in.open("InFile.txt");//打开文件
	if (!in)
	{
		cout << "can't open this file\n";
		return 0;
	}
	while (!in.eof())//读取单词
	{
		in.get(c);//用in>>不行
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) ||c == '\'')//判断c是否为字母
		{
			if (c <= 90 && c != '\'')//如果是大写字母转换为小写字母
				c = c + 32;
			s = s + c;
		}
		else//成功读取一个单词
		{
			if (s != "")//排除连续出现多个非字母字符的情况
			{
				r = L->next;//r初始化为首元结点，用来遍历链表
				p = L;//p初始化为头结点，用来记录r的前置结点
				while (r)
				{
					if (s == r->data.w)//该单词已在表中
					{
						r->data.num++;
						break;
					}
					p = r;
					r = r->next;
				}
				if (r == NULL)//单词不存在表中
				{
					l++;
					LinkList	q;//生成新结点
					q = new	LNode;
					q->data.w = s;
					q->data.num++;
					p->next = q;
					q->next = NULL;
				}
				s = "";//s清空
			}
		}
	}
	in.close();
	return	l;//返回链表长度
}

void	insertbst(BSTree &T, string e)//二叉排序树的插入
{
	if (!T)//T为空，找到插入位置
	{
		BSTree	s;
		s = new	BSTNode;
		s->data.w = e;
		s->data.num++;
		s->lchild = s->rchild = NULL;//叶子结点，左孩子，右孩子都为空
		T = s;
	}
	else
		if (e < T->data.w)
			insertbst(T->lchild, e);
		else
			if (e > T->data.w)
				insertbst(T->rchild, e);
			else//如果此单词和当前结点的单词数据相等，单词数加1
				T->data.num++;
}

void	input_bst(BSTree	&T)//创建二叉排序树
{
	string s = "";//临时存储单词
	char c;//临时存储字母
	ifstream	in;//读文件
	in.open("InFile.txt");//打开文件
	if (!in)
	{
		cout << "can't open this file\n";
		return;
	}
	while (!in.eof())//读取单词
	{
		in.get(c);//用in>>不行
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)|| c == '\'')//判断c是否为字母
		{
			if (c <= 90 && c != '\'')//如果是大写字母转换为小写字母
				c = c + 32;
			s = s + c;
		}
		else//成功读取一个单词
		{
			if (s != "")//排除连续出现多个非字母字符的情况
				insertbst(T, s);
			s = "";
		}
	}
}

int	Hash(string s)//哈希函数   首字母在字母表中的下标 乘 尾字母在字母表中的下标
{
	char	a, b;//a为s首字母，b为末字母
	a = s[0];
	b = s[s.length() - 1];
	return	(int(a - 96)*int(b - 96)) % maxsize;
}


void	input_hash_openadd(HashTable	HT[])//基于开放地址法的哈希查找，创建哈希表
{
	string s = "";//临时存储单词
	char c;//临时存储字母
	ifstream	in;//读文件
	int	key,n,k;//key记录计算出哈希函数的值,n记录出现冲突的次数，k用来处理冲突
	in.open("InFile.txt");//打开文件
	if (!in)
	{
		cout << "can't open this file\n";
		return;
	}
	while (!in.eof())//读取单词
	{
		in.get(c);//用in>>不行
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)|| c == '\'')//判断c是否为字母
		{
			if (c <= 90 && c != '\'')//如果是大写字母转换为小写字母
				c = c + 32;
			s = s + c;
		}
		else//成功读取一个单词
		{
			if (s != "") // 排除连续出现多个非字母的字符情况
			{
				k = 0;
				n = 0;
				key = Hash(s);
				while (1)
				{
					if (HT[key].data.w == s)//该单词已存在
					{
						HT[key].data.num++;
						HT[key].n = n;
						break;
					}
					else
					{
						if (HT[key].data.w == "")//新单词
						{
							HT[key].data.w = s;
							HT[key].data.num++;
							HT[key].n = n;
							break;
						}
						else//发生冲突
						{
							k++;
							key = (key + k) % maxsize;
							n++;
						}
					}
				}
				s = "";
			}
		}
	}
}

void	input_hash_linklist(hash_LNode HT)//基于链地址法的哈希查找，创建哈希链表
{
	LinkList	a, b;
	string s = "";//临时存储单词
	char c;//临时存储字母
	ifstream	in;//读文件
	int	key;//key记录计算出哈希函数的值
	in.open("InFile.txt");//打开文件
	if (!in)
	{
		cout << "can't open this file\n";
		return;
	}
	while (!in.eof())//读取单词
	{
		in.get(c);//用in>>不行
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)||c == '\'')//判断c是否为字母
		{
			if (c <= 90 && c != '\'')//如果是大写字母转换为小写字母
				c = c + 32;
			s = s + c;
		}
		else//成功读取一个单词
		{
			if (s != "") // 排除连续出现多个非字母的字符情况
			{
				key = Hash(s);
				if (!HT[key].L)//新key值,新单词
				{
					LinkList	q;
					q = new	LNode;
					q->data.w = s;
					q->data.num = 1;
					q->next = NULL;
					HT[key].L = q;
				}
				else
				{
					a = HT[key].L;//a为当前key值链表的首元结点，用来遍历链表
					while (a)
					{
						if (a->data.w == s)
						{
							a->data.num++;
							break;
						}
						b = a;//b用来记录a的前置结点
						a = a->next;
					}
					if (!a)//新单词
					{
						LinkList	q;
						q = new	LNode;
						q->data.w = s;
						q->data.num = 1;
						q->next = NULL;
						b->next = q;
					}
				}
			}
			s = "";
		}
	}
}

void	outfile_hash_linklist(hash_LNode HT, string f)//写文件，基于链地址法哈希
{
	LinkList	p;
	SqList	jay;
	int j = 0;//顺序表下标
	jay.elem = new	Word[maxsize];
	for (int i = 0; i < maxsize; i++)//将哈希链表里的数据转移到顺序表
	{
		if (HT[i].L)
		{
			p = HT[i].L;
			while (p)
			{
				jay.elem[j] = p->data;
				j++;
				p = p->next;
			}
		}
	}
	jay.len = j;
	qsort_sqlist(jay, 0, jay.len - 1);//调用快排
	ofstream	outfile(f);//写入文件
	outfile << jay.len << endl;
	for (int i = 0; i < jay.len; i++)
		outfile << jay.elem[i].w << "  " << jay.elem[i].num << endl;
	cout << "词频统计成功！\n";
}

void	outfile_hash(HashTable	HT[],string	f)//生成新文件，基于开放地址法哈希
{
	LinkList	L,r,p;//将哈希表里的数据转移到链表里，用来排序
	L = new	LNode;
	L->next = NULL;
	p = L;
	int	n = 0;
	for (int i = 0; i < maxsize; i++)
	{
		if (HT[i].data.w != "")//在哈希表中取到一个单词
		{
			r = L->next;
			n++;
			while (r&&r->data.w < HT[i].data.w)//找到第一个比HT[i]的数据小的结点
			{
				p = r;
				r = r->next;
			}
			LinkList	q;//生成新结点
			q = new	LNode;
			q->data = HT[i].data;
			p->next = q;
			q->next = r;
		}	
	}//完成排序
	ofstream	outfile(f);
	outfile << n << endl;
	while (L->next)
	{
		L = L->next;
		outfile << L->data.w << "  " << L->data.num << endl;
	}
	cout << "词频统计成功！\n";
}

void	InOrder_traver(BSTree T, Word w[] ,int &i)//中序遍历二叉树
{
	if(T)
	{
		InOrder_traver(T->lchild, w, i);
		w[i] = T->data;
		i++;//i最后为word个数
		InOrder_traver(T->rchild, w, i);
	}
}

void	outfile_bst(BSTree T,string s)//基于二叉排序树统计词频
{
	ofstream	outfile(s);
	Word	*w;
	int	i = 0;
	w = new	Word[maxsize];
	InOrder_traver(T, w, i);//中序遍历二叉树，将二叉排序树里的数据有序地放在数组里
	outfile << i  << endl;
	for (int j = 0; j < i; j++)
	{
		outfile << w[j].w << "  " << w[j].num << endl;
	}
	cout << "词频统计成功！\n";
}


void	outfile_sqlist(SqList jay,string f)//生成新文件，词频统计，顺序表
{
	ofstream	outfile(f);
	outfile << jay.len << endl;
	for (int i = 0; i < jay.len; i++)
		outfile << jay.elem[i].w << "  " << jay.elem[i].num << endl;
	cout << "词频统计成功！\n";
}

void	outfile_LinkList(LinkList L, string f,int l)//生成新文件，词频统计,链表
{
	ofstream	outfile(f);
	LinkList	r;
	r = L->next;
	outfile << l << endl;
	while (r)
	{
		outfile << r->data.w << "  " << r->data.num << endl;
		r = r->next;
	}
	cout << "词频统计成功\n";
}

void	sort_linklist(LinkList &L, int n)//链表排序
{
	LinkList	a, b, q;
	int i, j;
	for (i = 0; i < n - 1; i++)//冒泡
	{
		q = L;//q记录a的前驱结点
		a = L->next;//a为当前结点
		b = a->next;//b记录a的后置结点
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a->data.w > b->data.w)
			{
				a->next = b->next;
				q->next = b;
				q = b;
				q->next = a;
			}
			else
			{
				q = q->next;
				a = a->next;
			}
			b = a->next;
		}
	}
}

int	findword_sqlist()//单词查找，线性表
{
	SqList	wu;
	wu.elem = new	Word[maxsize];
	string	s;//待查找单词
	int	n = 0;//比较次数
	int	flag = 0;//判断单词是否存在
	int m;//记录待查找单词下标
	time_t	start, end;//记录时间
	float	Asl,l;
	cout << "请输入待查找的单词：";
	cin >> s;
	for (int i = 0; i < s.length(); i++)//如果是大写字母则转换为小写
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = s[i] + 32;
	}
	input_sqlist(wu);//将文件里的数据读入线性表
	l = wu.len;
	Asl = (l + 1) / 2;//计算asl
	start = clock();//开始时间
	for (int i = 0; i < wu.len; i++)
	{
		n++;
		if (wu.elem[i].w == s)
		{
			flag = 1;//查找成功
			m = i;
			break;
		}
	}
	end = clock();//结束时间
	if (flag == 1)
	{
		cout << "\n此单词的词频为： " << wu.elem[m].num << endl;
		cout << "查找该单词所花时间为： " << end - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
		cout << "平均查找长度： " << Asl << endl;
		cout << "查找该单词的比较次数： " << n << endl;
	}
	else
	{
		cout << "查找失败！" << endl;
	}
	cout << "\n请按任意键返回！" << endl;
	string c;//接收一个或多个字符
	cin >> c;
	return	1;
}

int	findword_linklist()//单词查找，链表
{
	LinkList	L,r;
	L = new	LNode;
	L->next = NULL;
	string	s;//待查找单词
	int	n = 0;//比较次数
	time_t	start, end;//记录时间
	float	Asl, l;//l为链表长度
	cout << "请输入待查找的单词：";
	cin >> s;
	for (int i = 0; i < s.length(); i++)//如果是大写字母则转换为小写
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = s[i] + 32;
	}
	l=input_LinkList(L);//将文件中的数据读入链表
	r = L->next;//r初始化为首元结点
	Asl = (l + 1) / 2;
	start = clock();
	while(r)
	{
		n++;
		if (r->data.w == s)
			break;
		r = r->next;
	}
	end = clock();
	if (r)//查找成功
	{
		cout << "\n此单词的词频为： " << r->data.num << endl;
		cout << "查找该单词所花时间为： " << end - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
		cout << "平均查找长度： " << Asl << endl;
		cout << "查找该单词的比较次数： " << n << endl;
	}
	else
	{
		cout << "查找失败！" << endl;
	}
	cout << "\n请按任意键返回！" << endl;
	string c;//接收一个字符
	cin >> c;
	return	1;
}

int	zheban(SqList wu, int i, int j,string s,int &m,int &n)//折半查找函数
{
	n = 0;
	while (i <= j)
	{
		m = (i + j) / 2;
		n++;
		if (s == wu.elem[m].w)
		{
			return	1;
		}
		else
			if (s < wu.elem[m].w)
				j = m - 1;
			else
				i = m + 1;
	}
	return	0;
}

int	zhebanfind(SqList wu)//单词查找，折半查找
{
	int	i, j, n, m;//n：比较次数
	string	s;//待查找单词
	float	sum = 0;//所有单词的查找总数
	int	flag = 0;//判断单词是否存在
	time_t	start, end;//记录时间
	float	Asl;
	i = 0;
	j = wu.len-1;
	for (int k = 0; k < wu.len; k++)//计算asl，遍历所有单词
	{
		s = wu.elem[k].w;
		zheban(wu, i, j, s, m, n);
		sum += n;
	}
	Asl = sum / wu.len;
	cout << "请输入待查找的单词：";
	cin >> s;
	for (int i = 0; i < s.length(); i++)//如果是大写字母则转换为小写
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = s[i] + 32;
	}
	start = clock();//开始查找
	flag=zheban(wu, i, j, s, m,n);
	end = clock();//查找结束
	if (flag == 1)
	{
		cout << "\n此单词的词频为： " << wu.elem[m].num << endl;
		cout << "查找该单词所花时间为： " << end - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
		cout << "平均查找长度： " << Asl << endl;
		cout << "查找该单词的比较次数： " << n << endl;
	}
	else
	{
		cout << "查找失败！" << endl;
	}
	cout << "\n请按任意键返回！" << endl;
	string c;//接收一个字符
	cin >> c;
	return	1;
}

BSTree	bst_find(BSTree T, string s,int &m)//递归，在树中查找单词 m：查找次数
{
	m++;
	if (!T || s == T->data.w)
		return	T;
	else
		if (T->data.w > s)
			return	bst_find(T->lchild, s, m);
		else
			return	bst_find(T->rchild, s, m);
}

void	Asl_tree(BSTree T,BSTree t, float &n,int &l)//中序遍历二叉排序树,算Asl
{
	if (T)
	{
		Asl_tree(T->lchild, t, n, l);
		int	m = 0;
		bst_find(t, T->data.w, m);//计算当前结点单词的查找次数
		l++;//l记录树中结点个数
		n = n + m;
		Asl_tree(T->rchild, t, n, l);
	}
}

void	bst_findword(BSTree T)//基于二叉排序树的单词查找
{
	BSTree	t;
	string	s;//待查找单词
	int	n = 0;//比较次数
	float m = 0;//总比较次数
	int	l = 0;
	time_t	start, end;//记录时间
	float	Asl = 0;
	cout << "请输入待查找的单词：";
	cin >> s;
	for (int i = 0; i < s.length(); i++)//如果是大写字母则转换为小写
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = s[i] + 32;
	}
	Asl_tree(T, T,m,l);//算asl
	Asl = m / l;
	start = clock();
	t=bst_find(T, s, n);
	end = clock();
	if (t)
	{
		cout << "\n此单词的词频为： " << t->data.num << endl;
		cout << "查找该单词所花时间为： " << end - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
		cout << "平均查找长度： " << Asl << endl;
		cout << "查找该单词的比较次数： " << n << endl;
	}
	else
	{
		cout << "查找失败！" << endl;
	}
	cout << "\n请按任意键返回！" << endl;
	string c;//接收一个字符
	cin >> c;
}

Word	search_hash_openadd(HashTable HT[], string s, int &n)
{
	int	key;
	key = Hash(s);
	n = 1;
	if (HT[key].data.w == "" || HT[key].data.w == s)//不发生冲突
		return	HT[key].data;
	else
	{
		for (int i = 1; i < maxsize; i++)
		{
			n++;
			key = (key + i) % maxsize;
			if (HT[key].data.w == "" || HT[key].data.w == s)
				return	HT[key].data;
		}
	}
}

void	findword_hashadd(HashTable HT[])//单词查找，基于开放地址法的哈希查找
{
	Word	word;//查找成功返回的单词
	string	s;//待查找单词
	int	n = 0;//比较次数
	float m = 0;//总比较次数
	int	l = 0;//单词总数
	time_t	start, end;//记录时间
	float	Asl = 0;
	cout << "请输入待查找的单词：";
	cin >> s;
	for (int i = 0; i < s.length(); i++)//如果是大写字母则转换为小写
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = s[i] + 32;
	}
	for (int i = 0; i < maxsize; i++)//算asl
	{
		if (HT[i].data.num != 0)//哈希表当前下标位置存储着单词
		{
			m += (HT[i].n+1);//比较次数为冲突次数加1
			l++;
		}
	}
	Asl = m / l;
	start = clock();
	word=search_hash_openadd(HT, s, n);
	end = clock();
	if (word.w != "")
	{
		cout << "\n此单词的词频为： " << word.num << endl;
		cout << "查找该单词所花时间为： " << end - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
		cout << "平均查找长度： " << Asl << endl;
		cout << "查找该单词的比较次数： " << n << endl;
	}
	else
	{
		cout << "查找失败！" << endl;
	}
	cout << "\n请按任意键返回！" << endl;
	string c;//接收一个字符
	cin >> c;
}

void	findword_hashlinklist(hash_LNode HT)//单词查找，基于哈希链地址法
{
	LinkList	q;
	string	s;//待查找单词
	int key, n, l;//key:待查找单词关键字 num:待查找单词词频 n:当前单词的比较次数 l:单词个数
	float m = 0;//总比较次数
	l = 0;
	time_t	start, end;//记录时间
	float	Asl = 0;
	cout << "请输入待查找的单词：";
	cin >> s;
	for (int i = 0; i < s.length(); i++)//如果是大写字母则转换为小写
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = s[i] + 32;
	}
	for (int i = 0; i < maxsize; i++)//计算总查找次数
	{
		n = 0;
		if (HT[i].L)
		{
			q = HT[i].L;
			while (q)
			{
				n++;
				l++;
				m = m + n;
				q = q->next;
			}
		}
	}
	Asl = m / l;
	start = clock();
	key = Hash(s);//由哈希函数计算地址
	q = HT[key].L;
	n = 0;
	while (q)//遍历链表
	{
		n++;
		if (q->data.w == s)//查找成功跳出循环
		{
			break;
		}
		q = q->next;
	}
	end = clock();
	if (q)
	{
		cout << "\n此单词的词频为： " << q->data.num << endl;
		cout << "查找该单词所花时间为： " << end - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
		cout << "平均查找长度： " << Asl << endl;
		cout << "查找该单词的比较次数： " << n << endl;
	}
	else
	{
		cout << "查找失败！" << endl;
	}
	cout << "\n请按任意键返回！" << endl;
	string c;//接收一个字符
	cin >> c;
}

int	shunxufind_sqlist()//基于顺序表,顺序查找
{
	string	s;
	int	t;
	SqList	wu;//定义顺序表
	wu.elem = new	Word[maxsize];//开辟空间
	while(1)
	{
		cover4();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://词频统计
			system("CLS");
			input_sqlist(wu);
			qsort_sqlist(wu, 0, wu.len - 1);
			outfile_sqlist(wu, "OutFile1.txt");
			cout << "请输入您接下来要进行的操作：\n" << endl;
			break;
		case	2116://单词查找
			system("CLS");
			cover12();
			findword_sqlist();
			system("CLS");
			cout << "请输入您接下来要进行的操作：\n" << endl;
			break;
		case	2025:
			system("CLS");
			return	1;
		default:
			system("CLS");
			cout << "您的输入有误，请重新输入：" << endl;
		}
	}
}

int	shunxufind_linklist()//基于链表，顺序查找
{
	string	s;
	int	t,l;//l记录链表长度
	LinkList	L;
	L = new	LNode;
	L->next = NULL;
	while (1)
	{
		cover7();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://词频统计
			system("CLS");
			l=input_LinkList(L);
			sort_linklist(L,l);
			outfile_LinkList(L, "OutFile2.txt", l);
			cout << "请输入您接下来要进行的操作：\n" << endl;
			break;
		case	2116://单词查找
			system("CLS");
			cover12();
			findword_linklist();
			system("CLS");
			cout << "请输入您接下来要进行的操作：\n" << endl;
			break;
		case	2025:
			system("CLS");
			return	1;
		default:
			system("CLS");
			cout << "您的输入有误，请重新输入：" << endl;
			break;
		}
	}
}

int	shunxufind_list()//基于线性表，顺序查找
{
	int	t;
	string	s;
	while (1)
	{
		cover3();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://基于顺序表的顺序查找
			system("CLS");
			shunxufind_sqlist();
			break;
		case	2116://基于链表的顺序查找
			system("CLS");
			shunxufind_linklist();
			break;
		case	2025://返回上一级
			system("CLS");
			return	1;
		default:
			system("CLS");
			cout << "您的输入有误，请重新输入：" << endl;
			break;
		}
	}
}

int	zhebanfind_list()//基于线性表，折半查找
{
	SqList	wu;
	wu.elem = new	Word[maxsize];
	string	s;
	int	t;
	input_sqlist(wu);
	qsort_sqlist(wu, 0, wu.len - 1);
	while (1)
	{
		cover6();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://词频统计
			system("CLS");
			outfile_sqlist(wu, "OutFile3.txt");
			cout << "请输入您接下来要进行的操作：\n" << endl;
			break;
		case	2116://单词查找
			system("CLS");
			cover12();
			zhebanfind(wu);
			system("CLS");
			cout << "请输入您接下来要进行的操作：\n" << endl;
			break;
		case	2025://返回上一级
			system("CLS");
			return 1;
		default:
			system("CLS");
			cout << "您的输入有误，请重新输入：" << endl;
			break;
		}
	}
}

int	find_list()//基于线性表的查找
{
	string	s;
	int	t;
	while (1)
	{
		cover2();
		cin >> s;
		t = Hash(s);
		switch(t)
		{
		case	2209://基于线性表，顺序查找
			system("CLS");
			shunxufind_list();
			break;
		case	2116://基于线性表，折半查找
			system("CLS");
			zhebanfind_list();
			break;
		case	2025:
			system("CLS");
			return	1;
		default:
			system("CLS");
			cout << "您的输入有误，请重新输入：" << endl;
			break;
		}
	}
}

int	bst_find()//基于二叉排序树的查找
{
	BSTree Tree;
	Tree = NULL;
	input_bst(Tree);
	string	s;
	int	t;
	while (1)
	{
		cover8();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://词频统计
			system("CLS");
			outfile_bst(Tree, "OutFile4.txt");
			cout << "请输入您接下来要进行的操作：\n" << endl;
			break;
		case	2116://单词查找
			system("CLS");
			cover12();
			bst_findword(Tree);
			system("CLS");
			cout << "请输入您接下来要进行的操作：\n" << endl;
			break;
		case	2025://返回上一级
			system("CLS");
			return 1;
		default:
			system("CLS");
			cout << "您的输入有误，请重新输入：" << endl;
			break;
		}
	}
}

int	open_address_hash()//基于开放地址法的hash查找
{
	HashTable	wu[maxsize];
	input_hash_openadd(wu);
	string	s;
	int	t;
	while (1)
	{
		cover10();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://词频统计
			system("CLS");
			outfile_hash(wu, "OutFile5.txt");
			cout << "请输入您接下来要进行的操作：\n" << endl;
			break;
		case	2116://单词查找
			system("CLS");
			cover12();
			findword_hashadd(wu);
			system("CLS");
			cout << "请输入您接下来要进行的操作：\n" << endl;
			break;
		case	2025://返回上一级
			system("CLS");
			return 1;
		default:
			system("CLS");
			cout << "您的输入有误，请重新输入：" << endl;
			break;
		}
	}
}

int	hash_linklist()//基于链地址法的哈希查找
{
	hash_LNode	HT;
	input_hash_linklist(HT);
	string	s;
	int	t;
	while (1)
	{
		cover11();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://词频统计
			system("CLS");
			outfile_hash_linklist(HT, "OutFile6.txt");
			cout << "请输入您接下来要进行的操作：\n" << endl;
			break;
		case	2116://单词查找
			system("CLS");
			cover12();
			findword_hashlinklist(HT);
			system("CLS");
			cout << "请输入您接下来要进行的操作：\n" << endl;
			break;
		case	2025://返回上一级
			system("CLS");
			return 1;
		default:
			system("CLS");
			cout << "您的输入有误，请重新输入：" << endl;
			break;
		}
	}
}

int	find_hash()//基于哈希表的查找
{
	string	s;
	int	t;
	while (1)
	{
		cover9();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://基于开放地址法的哈希查找
			system("CLS");
			open_address_hash();
			break;
		case	2116://基于链地址法的哈希查找
			system("CLS");
			hash_linklist();
			break;
		case	2025:
			system("CLS");
			return	1;
		default:
			system("CLS");
			cout << "您的输入有误，请重新输入\n";
		}
	}
}

int	main()
{
	string s;
	int  t;
	while (1)
	{
		cover1();
		cin >> s;
		t = Hash(s);
		switch (t)
		{
		case	2209://基于线性表查找
			system("CLS");
			find_list();
			break;
		case	2116://基于二叉排序树的查找
			system("CLS");
			bst_find();
			break;
		case	2025://基于哈希表的查找
			system("CLS");
			find_hash();
			system("CLS");
			break;
		case	1936:
			cout << "欢迎再次使用。~ \n";
			return	0;
		default:
			system("CLS");
			cout << "您的输入有误，请重新输入：" << endl;
			break;
		}
	}
}