#include<bits/stdc++.h>
using namespace std;
long long m,a[100005],maxx=-999999999999;
long n;
void dfs(int step){
	if(step==m){
		for(int i=1;i<=n;i++)
		{
			int p=1;
			for(int j=1;j<=n;j++)
			{
				if((i!=j)&&(a[i]==a[j])){
					p++;
				}
			}
			if(maxx<=p) maxx=p;
			return;
		}
	}
	for(int i=1;i<=n;i++){
		a[i]++;
		dfs(step+1);
		a[i]--;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(0);
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


