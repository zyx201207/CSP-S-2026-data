#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,m,mxw;
long long a[N][31],y[N],t,fs[35],vis[N],s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>t;
		y[i]=t;
		int j=0;
		while(t){
			a[i][j]=t%2;
			fs[j]+=a[i][j];
			t/=2;
			++j;
		}
		mxw=max(mxw,j);
	}
	t=n;
	for(int i=mxw;i>=0;--i){
		if(fs[i]<m){
			for(int j=1;j<=n;++j){
				if(a[j][i]==1)y[j]-=(1<<i);
			}
		}
	}
	sort(y+1,y+n+1);
	s=y[n];
	for(int i=n-1;i>=n-m+1;--i){
		s=s&y[i];
	}
	cout<<s;
	return 0;
}
