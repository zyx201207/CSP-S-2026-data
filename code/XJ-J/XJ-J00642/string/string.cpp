#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
string a;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		char y;
		cin>>y;
		for(int j=1;j<=x;j++){
			a+=y;
		}
	}
	int ans=0;
	for(int i=0;i<a.size()/2;i++){
		int j=a.size()-i-1;
		if(a[i]!=a[j]) ans++;
	}
	cout<<ans;
	
	return 0;
}
