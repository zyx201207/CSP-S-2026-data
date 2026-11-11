#include<bits/stdc++.h>

using namespace std;
int n,m;
int a[300010]={0};
int c[500010]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];//输入 
		c[a[i]]++;//计数
		int f=0,x=0;
		for(int j=1;j<=i-1;j++){
			if(a[i]==a[j]){
				f=1;
				x=j;
			}
		}//找
		for(int j=x;j<=i;j++){
			a[j]=0;
		} //删
		/*
		for(int j=1;j<=n;j++){
			//a[j]>数
			//c[i]>桶
			c[a[j]]++; 
		}//计数
		*/
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}/*
4 3
1 2 1 3
*/
