#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005][505];
int s[100005],e[100005];
int g[505][505];
int x[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int sum=0;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int j=1;j<=x[i];j++){
			int k,t;
			cin>>k>>t;
			b[k][i]=t;
			if(i==1) sum+=t;
		}
	}
	for(int i=1;i<=q;i++) cin>>s[i]>>e[i];
	if(n<=2) for(int i=1;i<=q;i++) cout<<sum<<endl;
}
