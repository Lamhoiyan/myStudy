线性表的顺序存储结构
线性链表 
静态链表
循环链表
双向链表

二叉排序树（二叉搜索树、二叉查找树（BST、B树）），节点左边的都比节点小
平衡二叉树（AVL树），左右子树高度差的绝对值不超过1，左右都是平衡二叉树
红黑树（RBT）

优先队列
堆

List 是可以记录插⼊顺序的。 
 
Map 可以重载⽐较函数，就可以按照map⾥⾯的元素进⾏排序。 

# Set
Set ⾥⾯元素其实是按照hashcode进⾏排序的。

# priority queue
底层是大顶堆，优先级高的先输出。
这个数据结构包含在queue这个头文件里。

## 常用函数
```
empty()
size()
push()
pop()
top()
```

# vector
min_element(arr.begin(), arr.end()) - arr.begin();
arr.erase(arr.begin()+cur); 
vector有at来访问数组，at()有对元素是否越界进行判断，如果越界，马上抛出异常 out_of_range
（但是，这个异常是跟踪进去调试的时候才会出现的），安全性高但是效率低

## 实现

```
//内置数据类型
priority_queue<int> myPriorityQueue;

//自定义数据类型
struct Complex{
    int real;
    int imag;
    bool operator< (Complex c)const{
        return real*real + imag*imag < c.real + c.real + c.imag * c.imag;
    }
}
priority_queue<Complex> myPriorityQueue;

//小顶堆
priority_queue<int,vector<int>,greater<int>> myPriorityQueue;
```

## find
使用find()，返回的是迭代器。如果需要判断是否找到该元素，可以用==s.end()来判断。
底层使用红黑树

# vector(向量)
可以实现图论中的邻接表。 
vector（向量）的常⽤函数。 
empty()  
size() 
push_back() 
pop_back() 
insert() 
erase() 
clear() 
begin() end() 获取⾸尾元素的迭代器 

# queue（队列）
## 常⽤函数
empty() 
size() 
push() 
pop() 
front() back() 获取两边的元素

先进先出的问题都可以考虑队列：
约瑟夫问题（循环队列）
队列也可以⽤于宽度优先搜索 

# 栈（后进先出）
函数
empty() 
size() 
push() 
pop() 
top() 
求解逆序输出问题


括号匹配问题
表达式求解（符号栈和数字栈）

# map
map内部自建一颗红黑树，这颗树具有对数据自动排序的功能，所以在map内部所有的数据都是有序的，有了map容器之后会发现省了很多事，不用自己对数据重新排序，而且迭代器的使用也方便输出。map容器相对于数组的好处就是用多少内存就申请多少，不会浪费空间。

map中的元素自动按照key升序排列，不能对map使用sort函数。

## 常用函数

通过一个条目对象删除:
erase(); 

删除一个范围:
erase(); 

添加数据:
insert()

查找:
find()

两个容器交换:
swap()

删除所有元素：
clear()

返回指定元素出现的次数
count

大小
size()

# 并查集
- 初始化
把每个点所在集合初始化为其自身。
通常来说，这个步骤在每次使用该数据结构时只需要执行一次，无论何种实现方式，时间复杂度均为O(N)。
- 查找
查找元素所在的集合，即根节点。
- 合并
将两个元素所在的集合合并为一个集合。
通常来说，合并之前，应先判断两个元素是否属于同一集合，这可用上面的“查找”操作实现。

并查集由一个整数型的数组和两个函数构成。数组pre[]记录了每个点的前导点是什么，函数find是查找，join是合并。

pre[15]=3就表示15号的上级是3号。

```
int get(int x){
    //寻找该点的根节点
    if(data[x]==x) return x;
    else{
        data[x] = get(data[x]);
        return data[x];
    }
}
```

# 二叉树
## 二叉排序树
中序遍历这种树，就是一个升序序列。
```
#include <iostream>
using namespace std;

struct node{
    int d;
    node* left=nullptr;
    node* right=nullptr;
    node(int x):d(x){}
};

node* build(node* root, int x,int father){
    if(root==nullptr){
        root = new node(x);
        cout<<father<<endl;
    }
    else if(x<root->d){
        root->left = build(root->left,x,root->d);
    }
    else{
        root->right = build(root->right,x,root->d);
    }
    return root;
}

int main(){
    int N;
    cin>>N;
    
    int a=0;
    node* root=nullptr;
    for(int i=0;i<N;i++){
        cin>>a;
        root = build(root,a,-1);
    }
    
    return 0;
}
```

## 遍历
前序遍历+中序遍历 || 后序遍历+中序遍历 || 前序遍历+后序遍历+满二叉树， 可以确定唯一的二叉树。

### 前序+中序 求后序
```
node* build(string a,string b){
    if(a.size()==0) return nullptr;
    char ch = a[0];
    node* newNode = new node(ch);
    int pos = b.find(ch);
    
    newNode->left = build(a.substr(1,pos),b.substr(0,pos));
    newNode->right = build(a.substr(pos+1),b.substr(pos+1));
    return newNode;
}

//注意建左子树和右子树的时候，下标！！！
//a.substr(pos+1)意思是从pos+1一直到末尾的字符串
//a.substr(1,pos)的意思是从1开始，取pos个字符组成的字符串
```

### 后序+中序 求前序

### 后序+中序 求层次遍历
