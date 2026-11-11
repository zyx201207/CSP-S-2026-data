#include<bits/stdc++.h>
using namespace std;
vector<long long>a[510],b[500010],t[510];
long long csd,z,n,m,d,q,w[500010],v[500010],ans=0;
long long binarysearch(long long e,long long x){
	long long l=1,r=a[e].size(),mid;
	r--;
	while(l<=r){
		mid=(l+r)/2;
		if(a[e][mid]==x)return mid;
		else if(a[e][mid]<x)l=mid+1;
		else r=mid-1;
	}
	return -1;
}
void dfs(long long k,long long x,long long en,long long sum){
	if(a[k][x]==en){
		ans=min(ans,sum+t[k][x]);
		return ;
	}
	for(int i=1;i<a[k].size();i++){
		z=b[a[k][i]].size();
		if(a[k][i]==en)dfs(k,i,en,sum);
		if(z<=1)continue;
		for(int j=0;j<b[a[k][i]].size();j++){
			if(v[b[a[k][i]][j]]==1)continue;
			v[b[a[k][i]][j]]=1;
			dfs(b[a[k][i]][j],binarysearch(b[a[k][i]][j],a[k][i]),en,sum+t[k][i]+t[b[a[k][i]][j]][binarysearch(b[a[k][i]][j],a[k][i])]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>csd>>n>>m>>d>>q;
	long long x,y;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i].push_back(-1);
		t[i].push_back(-1);
		for(int j=1;j<=x;j++){
			cin>>y;
			b[y].push_back(i);
			a[i].push_back(y);
			cin>>y;
			t[i].push_back(y);
		}
	}
	for(int i=1;i<=n;i++){
		sort(a[i].begin(),a[i].end());
	}
	while(q--){
		cin>>x>>y;
		if(csd==20||csd==21){
			if(binarysearch(1,x)&&binarysearch(1,y)){
				cout<<w[x]+w[y]+t[1][binarysearch(1,x)]+t[1][binarysearch(1,y)];
			}else if(binarysearch(2,x)&&binarysearch(2,y)){
				cout<<w[x]+w[y]+t[2][binarysearch(2,x)]+t[2][binarysearch(2,y)];
			}else{
				for(int i=1;i<a[1].size();i++){
					if(binarysearch(2,a[1][i])){
						cout<<w[x]+w[y]+t[1][binarysearch(1,x)]+t[1][binarysearch(1,y)]+t[1][i]+t[2][binarysearch(2,a[1][i])];
						break;
					}
				}
			}
			cout<<endl;
			continue;
		}
		ans=LLONG_MAX;
		for(int i=1;i<=n;i++){
			if(binarysearch(i,x)){
				memset(v,0,sizeof(v));
				v[i]=1;
				dfs(i,binarysearch(i,x),y,w[x]+w[y]+t[i][binarysearch(i,x)]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}