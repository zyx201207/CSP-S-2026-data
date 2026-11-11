#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int tikdt[10005];
int name[10005][10005],titdt[10005][10005];
int st[10005],ed[10005];
int a[10005],ans[10005];
long long la;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>tikdt[i];
	}
	for(int i=1;i<=n;++i){
		cin>>la;
		for(int j=1;j<=la;++j){
			cin>>name[i][j]>>titdt[i][j];
		}
	}
	for(int i=1;i<=q;++i){
		cin>>st[i]>>ed[i];
	}
	while (n--)
	{
		int b[10005];
		int sum;
		for (int i=sum-1;i<n;i++)
		{
			b[i]=a[i];
			for (int j=sum-1;j<i;j++)
			{
				if (b[j]==b[i])
				{
					for (int k=j+1;k<=i;k++)
					{
						b[k]=0;
					}
				}
			}
		}
		for (int i=0;i<n;i++) ans[b[i]]++;
		sum++;
	}
	for (int i=1;i<=m;i++) cout << ans[i] << " ";
	return 0; 
}
