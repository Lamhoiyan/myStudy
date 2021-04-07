http://www.cplusplus.com/reference/ 

# 字符串
对于字符串的插入，在遍历过程中不要使用a.size()作为遍历的条件，因为在遍历过程中size会改变。所以会报错。建议开一个新的字符串，然后用+=。

## 输入
string a;
getline(cin,a);//可以获取空格后的内容
getline(cin,a,'#');//可以获取#前面的内容

所以，以下的写法根本不可能让你推出while（）循环的：
while(getline(cin,line))
    cout<<line<<endl;

## 关于insert
可以使用str.insert(位置,数量，字符)或者str.insert(位置，字符串)

## find
s.find('\\',pos);
从pos位置开始往后找到//，返回//的下标

```
string a = "Hello";
cout<<a.find('o'); //这个答案是4
```

int二维数组最多开到100*100；
bool二维数组可以开到10000*10000；

## 其他
string a;

a.size() 或者a.length() //获取长度

to_string() 将一个整数转换为字符串
或者先将整数转换为字符，然后字符作为字符串的第一个字母。

reverse() 字符串反转

reverse(a.begin(),a.end());

getline(cin, s1); //读入一行字符串，忽略空格，用cin遇到空格就会退出

erase () 删除指定位置的元素
clear () 清空
substr() 找指定位置的字符串

# 输入输出

printf("%.3lf\n %d",t/n,n*2);   //%.3lf 表示保留三位小数后输出

小数还有一种%g的输出方式

## 保留几位有效数字
```
#include <iomanip>
cout.setf(ios::fixed);
cout<<setprecision(2);//后面接着要以该格式输出的内容

```

# 关于第K小数字
#include<bits/stdc++.h>
using namespace std;
long long n,k,a[5000010];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    nth_element(a,a+k,a+n);//使第k小整数就位 
    printf("%d",a[k]);//调用第k小整数
}

# 如何使用sort函数
#include<bits/stdc++.h>
using namespace std;
int x[5000005],k;
int main()
{
	int n;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&x[i]);
	sort(x,x+n);//快排
	printf("%d",x[k]);
}

# 四舍五入问题
(N+1)/2永远是往下面取整的，所以include <cmath>，然后用round、ceil、floor来选择

# 输入输出问题
while(scanf("%d",&a)!=EOF) //判断输入结束条件
while(cin>>n)//判断输入结束条件

最好scanf和cin不要混用，不知道会出现啥问题。

printf在stdio.h里面
printf("%d",a);

使用std::ios::sync_with_stdio(false);之后cin的效率和scanf差不多。

scanf不能接受空格、制表符Tab、回车等；当遇到回车，空格和tab键会自动在字符串后面添加’\0’，但是回车，空格和tab键仍会留在输入的缓冲区中。

gets能够接受空格、制表符Tab和回车等；可接受回车键之前输入的所有字符，并用’\0’替代 ‘\n’.回车键不会留在输入缓冲区中;

## 类型
- %ld 长整型
- %c 字符
- %o 八进制
- %x或者%X 十六进制
- %e或者E 以指数形式输出单、双精度
- %g 以%f或%e中较短的宽度输出
- %s 字符串

## 格式
- %5.2f 场宽为5，小数点后两位，不够5位右对齐输出
- %2d  输出宽度是2，不够2位右对齐输出
- %02d 输出宽度是2，不够2位前置补0

## 对齐问题
标 志	意义
\-	结果左对齐，右边填空格
\+	输出符号(正号或负号)
空格	输出值为正时冠以空格，为负时冠以负号
\#	对c、s、d、u类无影响；
对o类，在输出时加前缀o；
对x类，在输出时加前缀0x；
对e、g、f 类当结果有小数时才给出小数点。

## 格式化输入
（1）sscanf("zhoue3456 ", "%4s", str); //取指定长度的字符串       
          printf("str=%s\n", str);   //str="zhou";
（2）sscanf("zhou456 hedf", "%[^ ]", str); //取到指定字符为止的字符串,取遇到空格为止字符串    
          printf("str=%s\n", str);  //str=zhou456;
（3）sscanf("654321abcdedfABCDEF", "%[1-9a-z]", str); //取仅包含指定字符集的字符串
          printf("str=%s\n", str);  //str=654321abcded，只取数字和小写字符
（4）sscanf("BCDEF123456abcdedf", "%[^a-z]", str); //取到指定字符集为止的字符串       
           printf("str=%s\n", str);  //  str=BCDEF123456, 取遇到大写字母为止的字符串
（5）int a,b,c;
          sscanf("2015.04.05", "%d.%d.%d", &a,&b,&c); //取需要的字符串   
          printf("a=%d,b=%d,c=%d",a,b,c);  //  a=2015,b=4,c=5

# 闰年
(year%4==0 && year%100!=0)||(year%400==0)

# 重写比较函数
当⽐较函数的返回值为true，就是函数的第⼀个参数在第⼆个参数前⾯。 

# 四舍五入
ceil 
ﬂoor 
round 
int middle = (left+right)/2; 数字较⼤时可能出现 
int middle = left + (right-left) /2; 不会出现溢出问题 

# 判断是否数字
isdigit()函数在<cctype>⾥⾯

# 数据类型
longlong最⼤是2^64 -1，15位以内应该可以解决 

# 二维数组传参进入函数的方法
数组指针, int(*p)[5]; //指针p，指向大小为5的数组。
指针数组，int *p[5]; //数组p大小为5，每个元素都是指针。

# atoi函数？
```
int main(void)
{
    int n;
    char *str = "12345.67";
    n = atoi(str);
    printf("n=%d\n",n);
    return 0;
}
```

# itoa
itoa是广泛使用的非标准C语言和C++语言扩展功能。但因为它是一个非标准的C / C++语言功能,因此不能好好的被所有编译器使用。
在大多数Windows下的编译器通常在<cstdlib>头文件包含非标准函数。

itoa()函数把整数转换成字符串，并返回指向转换后的字符串的指针。整型转换字符数组函数

```
char *itoa (int value, char *str, int base );
//int value 被转换的整数，char *string 转换后储存的字符数组，int radix 转换进制数，如2,8,10,16 进制等，大小应在2-36之间。
```

```
#include<cstdlib>
#include<cstdio>
int main(void)
{
    int number=12345;
    char string[25];
    itoa(number,string,10);//按十进制转换
    printf("integer=%dstring=%s\n",number,string);
    itoa(number,string,16);//按16进制转换
    printf("integer=%dstring=%s\n",number,string);
    return 0;
}
```

# limits.h头文件

此外还有float.h，stdin.h两个文件

