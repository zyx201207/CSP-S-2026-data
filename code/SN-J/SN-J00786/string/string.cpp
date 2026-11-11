//杜吕俊泽 SN-J00786 西安辅轮学校 
#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,mx;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool op;
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
		if(x!=mx) op=false;
		mx=max(mx,x);
	}
	if(mx==true) cout<<"0";
	else cout<<mx;
	return 0;
}
