#include <iostream>
using namespace std;

const int N = 10;
int e[N][N],use[N],fa[N],ans;

void init(){
	/*	
		连边建图，e[i][j]==1表示i和j相邻
		a b c d e f g
		1 2 3 4 5 6 7
	*/
	
	e[1][2]=e[1][6]=1;
	e[2][1]=e[2][7]=e[2][3]=1;
	e[3][2]=e[3][4]=e[3][7]=1;
	e[4][3]=e[4][5]=1;
	e[5][4]=e[5][6]=e[5][7]=1;
	e[6][1]=e[6][5]=e[6][7]=1;
}

int fat(int x){
	if(fa[x]==x) return x;
	else{
		fa[x] = fat(fa[x]);
		return fa[x];
	}
}

void dfs(int x){
	if(x>7){
		for(int i=0;i<N;i++) fa[i]=i;
		
		for(int i=1;i<8;i++){
			for(int j=1;j<8;j++){
				if(use[i] && use[j] && e[i][j]){
					int a = fat(i);
					int b = fat(j);
					if(a!=b){
						fa[a] = b;
					}
				}
			}
		}
		
		int k=0;
		for(int i=1;i<8;i++){
			if(use[i] && (fa[i] == i){
				k++;
			}
		}
		if(k==1){
			ans++;
			return;
		}
	}
	
	use[x] = 1;
	dfs(x+1);
	use[x]=0;
	dfs(x+1);
}

int main(){
	init();
	dfs(1);
	cout<<ans;
	
	return 0;
}