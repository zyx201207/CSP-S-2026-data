#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],s,maxx,idx[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		idx[i]=i;
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	else if(m==n){
		s=a[1];
		for(int i=2;i<=n;i++){
			s&=a[i];
		}
		cout<<s;
	}
	else{
		do{
			s=a[idx[1]];
			for(int i=2;i<=m;i++){
				s&=a[idx[i]];
			}
			maxx=max(maxx,s);
		}
		while(next_permutation(idx+1,idx+n+1));
		cout<<maxx;
	}
	cout<<'\n';
	return 0;
}
