#include<bits/stdc++.h>
using namespace std;
char arr[20005];
int now=1;
int cnt=0;
void check(int a,char b){
	for(int i=now;i<now+a;i++){
		arr[i]=b;
	}
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		char y;
		cin>>x>>y;
		check(x,y);
		now+=x;
	}
	for(int i=1;i<=n/2;i++){
		if(arr[i]!=arr[now-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
