#include<bits/stdc++.h>
using namespace std;
long long c=0,n=0,m=0,d=0,q=0,be[100005],en[100005],sum=0,fa[100005];
long long a[505][50005]={0},t[505][50005]={0},w[000005]={0},k[505]={0};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			fa[a[i][j]]=t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>be[i]>>en[i];
		sum+=w[be[i]];
		sum+=w[en[i]];
		sum+=fa[be[i]];
		sum+=fa[en[i]];
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
