#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q,w[500010],k[510],a[500010],t[500010],s[100010][2],ans[100010];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];i++)cin>>a[j]>>t[j];
	}
	for(int i=1;i<=q;i++)cin>>s[i][1]>>s[i][2];
	
	for(int i=1;i<=q;i++){
		ans[i]=w[s[i][1]]+w[s[i][2]];
	}
	
	return 0;
}

