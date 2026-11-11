#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10,M = 3e5+10;
int a[N],q[N],l,r;
int v[M],wz[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(wz[a[j]]!=0){
				for(int k=wz[a[j]]+1;k<=r;k++)
					wz[q[k]]=0;
				r=wz[a[j]];
			}else{
				q[++r]=a[j];
				wz[a[j]]=r;
			}
		}
		for(int j=1;j<=r;j++){
			v[q[j]]++;
		}
		memset(q,0,sizeof(q));
		memset(wz,0,sizeof(wz));
	}
	for(int i=1;i<=m;i++)
		cout<<v[i]<<" ";
	return 0;
}