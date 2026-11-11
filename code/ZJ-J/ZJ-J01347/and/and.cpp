#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500001],po[51],mx,sum,tt,v[500001],vis[500001];
bool cmp(long long int x,long long int y){
	if(x>y)return 1;
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	po[0]=1;
	for(int i=1; i<=40; i++){
		po[i]=po[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=35; i>=0; i--){
		memset(v,0,sizeof(v));
		long long int l=0;
		for(int f=1; f<=n; f++){
			if(a[f]>=po[i]&&vis[f]==0){
				a[f]-=po[i];
				l++;
			}
			else{
				v[f]=1;
			}
		}
		if(l>=m){
			sum+=po[i];
			for(int f=1; f<=n; f++){
				if(v[f]==1){
					vis[f]=1;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}