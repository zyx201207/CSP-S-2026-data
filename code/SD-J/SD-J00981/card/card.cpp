#include<bits/stdc++.h>
#define io ios::sync_with_stdio();cin.tie();cout.tie();
using namespace std;
int a[500005],ans[300005],z[300005],t=0;
bool v[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	io;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			t=0;
			for(int j=i;j<=n;j++){
				if(!v[a[j]]){
					z[++t]=a[j];
					v[a[j]]=true;
				}
				else{
					while(z[t]!=a[j]){
						v[z[t--]]=false;
					}
				}
			}
			while(t>0){
				v[z[t]]=false;
				ans[z[t--]]++;
			}
		}
	}
	else{
		a[0]=-1;
		a[n+1]=99999999;
		for(int i=2;i<=n+1;i++){
			if(a[i]!=a[i-1]){
				ans[a[i-1]]=i-1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
//Trick||Treat!
/*
	9:36 想出n3做法想正解
	9:47 写栈n2做法 48pts
	10:05 过了3个大样例，第四个样例输出是乱码ccf上点心呗 
	10:10 到10:30没想出来就写t3 
	10:16 像dp但我不会): 
	11:43 性质A 52pts 
*/
