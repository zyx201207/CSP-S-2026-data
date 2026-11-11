#include<bits/stdc++.h>
//#define int long long
using namespace std;
int a[500050];
int b[500050];
int c[500050];
map<int,int> d;
int n,m,e;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(m>3000){
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>e;
		a[i]=e;
	}
	for(int i=i;i<=n;i++){
		c[a[i]]=i;
		b[a[i]]++;
		if(b[a[i]]>1){
			c[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			d[a[j]]++;
			j=c[a[j]]+1;
		}
	}
	for(auto i:d){
		cout<<i.second<<" ";
	}
	return 0;
}

