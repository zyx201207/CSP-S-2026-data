#include<iostream>
#include<stdio.h>
using namespace std;
int n,m;
int a[100010],desk[100010],ans[100010];
void put(int num){
	for(int i=0;i<n;i++){
		if(desk[i]==0){
			desk[i]=num;
			return ;
		if(desk[i]==num){
			for(int j=i;j<n;j++){
				desk[j]=0;
			}
			return ;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		memset(desk,0,sizeof(desk));
		for(int j=i;j<n;j++){
			put(a[j]);
		}
		for(int i=0;i<n;i++){
			ans[desk[i]]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
