#include<bits/stdc++.h>
using namespace std;
int n,m; 
int a[10050];
int b[10050];
int tong1[10050]; //上一次出现的下标 
int tong2[10050]; //每局游戏里的出现次数 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) tong1[j]=0;
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			if(tong1[b[j]]!=0){
				for(int k=tong1[b[j]];k<j;k++){
					if(tong1[b[k]]==k) tong1[b[k]]=0;
					b[k]=0;
				} 
					
			}
			tong1[b[j]]=j;
		}
		for(int j=i;j<=n;j++) tong2[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<tong2[i]<<" ";
	return 0;
} 
/*
4 3
1 2 1 3
*/
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
