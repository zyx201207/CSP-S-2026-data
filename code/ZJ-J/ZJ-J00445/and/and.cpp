#include<bits/stdc++.h>
using namespace std;
int n,m,a,b[200005][35],maxi=0,s[35],vis[200005],best[35],sum;
void u(int x,int p)
{
	int i=1;
	while(x>0){
		b[p][i++]=x%2;
		x/=2;
	}
	maxi=max(i-1,maxi);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		u(a,i);	
	}
	for(int i=maxi;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(b[j][i]==1&&vis[j]==0){
				s[i]++;
			}
		}
		if(s[i]>=m){
			best[i]=1;
			for(int j=1;j<=n;j++){
				if(b[j][i]==0){
					vis[j]=1;
				}
			}
		}
	}
	for(int i=1;i<=maxi;i++){
		sum+=best[i]*pow(2,i-1);
	}
	cout<<sum;
	return 0;
}