#include<bits/stdc++.h>
using namespace std;
char c[100001];
char e[100001];
int d[100001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0,cup=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		d[i]=a;
		e[i]=b;
		cup+=a;
	}
	for(int i=1;i<=1;i++){
		for(int j=1;j<=d[i];j++){
			c[j]=e[i];
			ans++;
		}
	}
	for(int i=2;i<=2;i++){
		for(int j=ans;j<=d[i];j++){
			c[j]=e[i];
		}
	}
	cout<<cup/2;
	
	return 0;
}
