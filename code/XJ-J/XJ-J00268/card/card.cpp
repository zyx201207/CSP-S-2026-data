#include<bits/stdc++.h>
using namespace std;
int n,m,a[5003],t[3003],jl[3003];
bool f=1;
vector<int>v[5003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(i!=1)if(a[i]<a[i-1])f=0;
	}
	if(m==2){
		int jl1=0,jl2=0;
		for(int i=1;i<=n;++i){
			if(a[i]==1)++jl1;
			else ++jl2;
		}
		if(a[n]==1){
			cout<<n<<' '<<jl2;
		}else cout<<jl1<<' '<<n;
		return 0;
	}
	if(f){
		for(int i=1;i<=n;++i){
			t[a[i]]=i;
		}
		for(int i=1;i<=m;++i){
			cout<<t[i]<<' ';
		}
		return 0;
	}
	v[n].push_back(a[n]);
	t[a[n]]=n;
	for(int i=n-1;i>=1;--i){
		if(t[a[i]]){
			v[i]=v[t[a[i]]];
		}else{
			v[i]=v[i+1];
			v[i].push_back(a[i]);
			t[a[i]]=i;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<v[i].size();++j){
			++jl[v[i][j]];
		}
	}
	for(int i=1;i<=m;++i){
		cout<<jl[i]<<' ';
	}
	return 0;
}
