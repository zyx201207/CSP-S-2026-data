#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string p;
	char q;
	int a;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a>>q;
		p[i]=q;
		sum+=a;
	}
	bool ququ=true;
	for(int i=1;i<n;i++){
		if(p[i]!=p[i+1]){
			ququ=false;
		}
	}
	if(ququ==true){
		cout<<"0";
		return 0;
	}
	cout<<sum/2;
	return 0;
}

