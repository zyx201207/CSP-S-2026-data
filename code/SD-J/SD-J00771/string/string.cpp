#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int m,cnt=1;
	cin>>m;
	char n[200005];
	for(int i=1;i<=m;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=cnt;j<=cnt+a;j++){
			n[j]=b;
		} cnt+=a;
	} cnt-=1;
	char a[100005],b[100005];
	if(cnt%2==0){
		for(int i=1;i<=cnt/2;i++){
			a[i]=n[i];
		} int sum=1;
		for(int i=cnt;i>=cnt/2+1;i--){
			b[sum]=n[i];
			sum++;
		} 
	} if(cnt%2==1){
		for(int i=1;i<=cnt/2;i++){
			a[i]=n[i];
		} int sum=1;
		for(int i=cnt;i>=cnt/2+2;i--){
			b[sum]=n[i];
			sum++;
		} 
	}
	int ct=0;
	for(int i=1;i<=cnt/2;i++){
		if(a[i]!=b[i]) ct++;
	} cout<<ct;
	return 0;
}
