#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+5;
int v[N];
int a[N];
int w[N];
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(v[a[j]]==0){
				v[a[j]]=1;
				w[a[j]]=j;
			}else{
				for(int k=w[a[j]];k<j;k++)v[a[k]]=0;
				v[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(v[j]!=0)cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
