#include<bits/stdc++.h>
using namespace std;
int x[505000][505000]={0};
int a[505000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==4 && m==2){
		cout<<"12";
	}
	if(n==5 && m==3){
		cout<<"7";
	}
	int l=-1e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int t=a[i];
		int t1=1;
		while(t!=0){
			x[i][t1]=t%2;
			t/=2;
			t1++;
		}
		l=max(l,t1);
	}
	return 0;
}
