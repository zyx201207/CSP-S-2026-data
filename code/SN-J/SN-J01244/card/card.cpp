#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int v[212345];
int a[212345],ans[212345];
stack<int> s;
void f(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
//		cout<<i<<endl;
		memset(v,0,sizeof v);
		for(int j=i;j<=n;j++){
//			for(int k=1;k<=m;k++) cout<<v[k]<<" ";
//			cout<<endl;
			if(v[a[j]]) while(s.top()!=a[j]) v[s.top()]--,s.pop();
			else s.push(a[j]),v[a[j]]++;
		}
		while(s.size()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++) {
		cout<<ans[i]<<" ";
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	f();
	return 0;
}
