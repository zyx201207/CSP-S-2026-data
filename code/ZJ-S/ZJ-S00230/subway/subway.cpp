#include<bits/stdc++.h>
using namespace std;
struct node{
	int val,end;
};
map<int,int> mp;
int v,m,n,d,p,w[500010],x[100010],y[100010],a[510][510],k[510],t[510][510],;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>v>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		scanf(" %d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf(" %d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf(" %d %d",&a[i][j],&t[i][j]);
		}
		if(k[i]-1!=0){
			mp[a[i][1]]=a[i][2];
		}
	}
	for(int i=1;i<=q;i++){
		scanf(" %d %d",%x[i],&y[i]);
	}
	long long ans=0;
	for(int i=1;i<=q;i++){
		int j=x[i];
		while(j!=y[i]){
			ans+=t[j][]
			j=mp[j];
			ans+=w[j];
		}
	}
	return 0;
}
