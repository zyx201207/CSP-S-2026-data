#include<iostream>
using namespace std;
int n,m,cnt=0;
int a[500005];
int c[300005];
int num[300005]={};
int appear[300005]={};
void clear(int x){
	for(int i=x;i<=cnt;i++){//清除c[i]的数字 
		if(num[i]<=i) num[i]=0;
		c[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int T=1;T<=n;T++){
		cnt=0;
		for(int i=1;i<=n;i++) num[i]=0;
		for(int i=T;i<=n;i++){
			int x=a[i];
			if(num[x]){
				int tmp=num[x];
				clear(num[x]);
				cnt-=(cnt-tmp+1);
				num[x]=++cnt;
				c[cnt]=x;
			}else{
				num[x]=++cnt;
				c[cnt]=x;
			}
		}
		for(int i=1;i<=m;i++) if(num[i]) appear[i]++;
	}
	for(int i=1;i<=m;i++) cout<<appear[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
num[i]表示i首次出现的下标 
if(num[i]) 有没有出现过(1/0) 
cnt表示总共有cnt张牌 
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
*/
