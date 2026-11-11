#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10; 
const int M=3e5+10;
int n,m,sum[M];
int a[N],ans[N];
bool yes[M];
int main(){
	freopen("card.in","r",stdin),freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{   int h=0;
		memset(yes,0,sizeof(yes));
		memset(ans,0,sizeof(ans));
		for(int j=i;j<=n;j++)
		{   if(yes[a[j]]==0)yes[a[j]]=1,ans[++h]=a[j];
			else {
				while(ans[h]!=a[j])yes[ans[h]]=0,h--;
			}
		}
		for(int j=1;j<=h;j++)sum[ans[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
}

