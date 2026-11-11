#include<bits/stdc++.h>
using namespace std;
char zm[200010];
long long gs[200010]; 
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char b;
		cin>>a>>b;
		zm[i]=b;
		gs[i]=a;
	}
	int t=1,w=n;
	long long ans=0;
	while(t<w)
	{
		if(zm[t]!=zm[w])
		{
			if(gs[t]>gs[w]){
				ans+=gs[w];
				gs[t]-=gs[w];
				gs[w]=0;
				w--;
			}
			else if(gs[t]==gs[w])
			{
				ans+=gs[w];
				gs[w]=0;
				gs[t]=0;
				w--;
				t++;
			}
			else
			{
				ans+=gs[t];
				gs[w]-=gs[t];
				gs[t]=0;
				t++;
			}
		}
		else
		{
			if(gs[t]>gs[w]){
				gs[t]-=gs[w];
				gs[w]=0;
				w--;
			}
			else if(gs[t]==gs[w])
			{
				w--;
				t++;
			}
			else
			{
				gs[w]-=gs[t];
				gs[t]=0;
				t++;
			}
		}
	}
	cout<<ans;
	return 0;
}