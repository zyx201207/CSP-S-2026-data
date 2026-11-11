#include<bits/stdc++.h>
using namespace std;
long long w[500010];
int t[510][500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int e=1;e<=n;e++){
		int k;
		cin>>k;
		for(int p=1;p<=k;p++){
			int a,b;
			cin>>a>>b;
			t[e][a]=b;
		} 
	}
	for(int r=1;r<=q;r++){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		for(int i=x;i<y;i++){
			ans=ans+t[i][i]+t[i][i+1];
		}
		cout<<ans<<endl;
	}

	return 0;
}
