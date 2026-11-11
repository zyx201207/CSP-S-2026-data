#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,k=0;
int a[N],v[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1] && i!=1){
			k=1;
		}
		v[a[i-1]]=i-1;
	}
	if(k==0){
		for(int i=1;i<=m-1;i++){
			cout<<v[i]<<' ';
		}
		cout<<n<<'\n';
	}
	return 0;
} 
