#include <bits/stdc++.h>
using namespace std;
int n,m,f;
char a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int t=1;
	if(n==1){
		f=1;
	}
	for(int i=1;i<=n;i++){
		cin>>m;
		char e;
		cin>>e;
		if(f==1){
			cout<<"0";
			return 0;
		}
		for(int i=1;i<=m;i++){
			a[t]=e;
			t++;
		}
	}
	t--;
	int cnt=0;
	for(int i=1;i<=t/2;i++){
		if(a[i]!=a[t-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}