#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=1e5+10;
int m,n;
int a[N],vis[M],sum[M];
int q[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool f=false;
	for(int i=1;i<=n;i++)
	{	cin>>a[i];
		if(a[i]<a[i-1]) f=true;	
	}
	if(!f){
		for(int i=1;i<=n;i++){
			if(a[i+1]!=a[i]) sum[a[i]]=i;
		}
		for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<"\n";
		for(int k=1;k<=m;k++) vis[k]=0;
		int r=0;
		for(int j=i;j<=n;j++)
		{
			int now=a[j];
		//	cout<<a[j]<<" ";
			if(!vis[now])
			{
				q[++r]=now;
				vis[now]=1;
			}
			else{
				while(q[r]!=now){
					vis[q[r]]=0;
					r--;
				} 	
			}
		}
	//	cout<<"\n";
		while(r>0)
		{
		//	int now=q.front();
			sum[q[r]]++;
			r--;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}
