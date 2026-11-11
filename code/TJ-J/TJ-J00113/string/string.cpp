#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,a;
	cin>>n;
	char c;
	if(n==1){
		cout<<"0";
	}
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		if(a==1){
			cout<<"0";
		}
	}
	return 0;
}
