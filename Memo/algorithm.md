# 背包问题
状态转移方程，是上阶段状态和上阶段的决策，的结果。

步骤
- 找子问题
- 确定状态
- 确定状态转移方程

## 0-1背包问题
https://blog.csdn.net/XuNeely/article/details/112025393

# 计算日期
## 给定日期计算周几
基姆拉尔森计算公式
W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1) mod 7

在公式中d表示日期中的日数，m表示月份数，y表示年数。
注意：在公式中有个与其他公式不同的地方：
把一月和二月看成是上一年的十三月和十四月，例：如果是2004-1-10则换算成：2003-13-10来代入公式计算。

## 日期类
c++的话，在头文件ctime里面。
time_t 获取的是秒，对应1970-1-1到目前的秒数
将time_t转化为tm类，用localtime或者gmtime。

### 获取当前时间的小时等信息
```
#include <iostream>
#include <ctime>
using namespace std;

int main(){
	time_t now = time(0);
	tm* tt = localtime(&now);
	//cout<<tt->tm_hour<<":"<<tt->tm_min;
	cout<<tt->tm_yday; 
	
	return 0;
} 
```

### 获取具体某天的小时等信息


## 排序问题
排序算法的复杂性最⼩是O(nlogn) 堆排序、快速排序、归并排序 


## 数组循环平移问题
加⼀个数组⻓度再取模。
int number[128] 
memset(number,0,sizeof(number) 

## 字符串匹配
### KMP算法
在目标串中寻找模式串。
对于模式串计算next数组。

```
int next[m];

void findNext(String a){
	int m = a.size();
	int j = 0;
	next[j] = -1;
	int i = next[j];

	while(j<m){
		if(i==-1 || a[i]==a[j]){
			i++;
			j++;
			next[j]=next[i];
		}
		else{
			i = next[i];
		}
	}

}
```

# 求最大公约数、最小公倍数
## 辗转相除法
```
int gcd(int x,int y){
	if(y==0){
		return x;
	}
	else{
		return gcd(y,x%y);
	}
}
```
## 最⼩公倍数（两个数的乘积*它们的最⼤公约数） 
## 最简真分数（分⼦和分⺟最⼤公约数是1） 

# 质数 
从2判断到sqrt（n），质数只能被1和其⾃身整除。
0和1不是素数。
素数的因子必须有两个。
素数筛法：找到一个素数，就把它的所有倍数标记成非素数。

```
//判断是否素数
bool isPrime(int x){
	for(int i=2;i<sqrt(x);i++){
		if(x%i==0) return false;
 	}
	return true;
}

//素数筛
如果i是一个素数

data[0]=false;
data[1]=false;
void in(int N){
	for(int i=2;i<N;i++){
		if(data[i]){
			for(int j=i*i;j<N;j+=i){
				data[j]=0;
			}
		}
	}
}i；
```
## 分解质因数
寻找小于sqrt(N)的所有素数，不断测试N是否能够整除该素数i，如果可以，i就是N的质因数。
又称为约数、整除问题。

# 快速幂
任何一个数字n都可以分解为若干2^k之和。

步骤：
将指数部分转换为二进制数.
```
int power(int a,int b){
	int result = 1;
	while(b>0){
		if(b%2==1){
			result = result * a;	
		}
		b/=2;
		a*=a;
	}
	return result;	
}
```

cmath里面用pow求x的y次方。

# 进制转换
C++只有八进制、十进制、十六进制。

# 位运算
- 右移>> 缩小两倍
- 左移<< 扩大两倍
- 与运算：
  - 判断奇偶性
	与运算，记得带上括号，比如(128 & 1);
  - 取余
  	
  - 另，负数按补码形式参加按位与运算。

# 数组模拟问题
比如旋转数组初始化，或者把数组顺时针旋转90度。

## 顺时针/逆时针旋转90度
就是将数组转置，然后每行首尾元素对称地变换位置。

```
void reverse(int n){
	//转置
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			rev[j][i]=dd[i][j];
		}
	}
		
	int tmp=0;

	//顺时针旋转，对行对称变换位置
	for(int i=0;i<n;i++){
		for(int j=0;j<=n/2;j++){
			tmp = rev[i][j];
			rev[i][j]=rev[i][n-j-1];
			rev[i][n-j-1]=tmp;
		}
	}

	//逆时针就是对每个列变换位置
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<n;j++){
			tmp = rev[i][j];
			rev[i][j] = rev[n-i-1][j];
			rev[n-i-1][j]=tmp;
		}
	} 
}
```

## 旋转数组
```
void chu(int n){
	int x=0,y=n-1;
	
	int num=1;
	while(x<=y){
		for(int i=x;i<=y;i++){
			dd[x][i]=num++;
		}
		
		for(int i=x+1;i<=y;i++){
			dd[i][y]=num++;
		}
		for(int i=y-1;i>=x;i--){
			dd[y][i]=num++;
		}
		for(int i=y-1;i>x;i--){
			dd[i][x]=num++;
		}
		
		x++;
		y--;
	}
}
```

# 多项式计算

# 稀疏矩阵

# 图论
## Kruskal 最小生成树

# 递归

## 全排列
### 全排列函数
```
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string s;
    while (cin>>s) {
        sort(s.begin(), s.end());
        cout<< s << endl;
        for (s.begin(); next_permutation(s.begin(), s.end());) {
            cout<< s << endl;
        }
        cout << endl;
    }
    return 0;
}
```

## 递归做法（全排列，字母从小到大排序）
https://www.nowcoder.com/practice/5632c23d0d654aecbc9315d1720421c1?tpId=40&tqId=21374&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking&tab=answerKey

```
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str;                      //定义全局字符串str;
void swap(int x, int y) {//交换字符串中x,y位置的字符；
    char temp = str[x];
    str[x] = str[y];
    str[y] = temp;
}
void func(int i, int j) {//递归函数
     
    if (i == j) {      //递归出口
        for (int m = 0; m < str.size(); ++m) {
            cout << str[m];
        }
        cout << endl;
    }
    else {
        for (int m = i; m < str.size(); ++m) {
            string s = str;   //先把str保存起来
            swap(i, m);
            sort(str.begin() + i+1, str.end());   //确定前面的字符后  把后面的字符串排序  比如abcd 当把ac交换后变成cbad，有了这一步会变成cabd。除了第一个a，后面的变得有序；
            func(i + 1, j);//下一层递归 
            str = s;           //递归结束后把str复原
        }
    }
}
int main() {
    int n;
    cin >> str;
    sort(str.begin(), str.end());//先统一排序
    n = str.size();
    func(0, n - 1);
}
```

图的遍历

# BFS

Dijkstra单源最短路径算法和Prim最小生成树算法都是类似的思想。其别名又叫BFS，属于一种盲目搜寻法，目的是系统地展开并检查图中的所有节点，以找寻结果。换句话说，它并不考虑结果的可能位置，彻底地搜索整张图，直到找到结果为止。

通常用队列实现。

一个数组，记录已被访问过的顶点
一个队列，存放每一层的节点

只要队列不空，重复以下操作：
1、队头顶点出队
2、依次检查u所有的邻接顶点w，如果w没有被访问过，就访问w，并且记录下来，入队。

# DFS
通常用栈实现。

# 哈希表
散列表（Hash table，也叫哈希表），是根据关键码值(Key value)而直接进行访问的数据结构。也就是说，它通过把关键码值映射到表中一个位置来访问记录，以加快查找的速度。这个映射函数叫做散列函数，存放记录的数组叫做散列表。
给定表M，存在函数f(key)，对任意给定的关键字值key，代入函数后若能得到包含该关键字的记录在表中的地址，则称表M为哈希(Hash）表，函数f(key)为哈希(Hash) 函数

## 哈希算法
### 
MD4
MD5
SHA-1

### 作用
文件校验
数字签名
鉴权协议