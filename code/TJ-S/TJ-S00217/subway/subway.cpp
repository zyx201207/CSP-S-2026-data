#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int c,n,m,d,q,cnt=0;
	int time_t=0;
	cin>>c>>n>>m>>d>>q;
	struct subway
	{
		int num;
		int sta[100000];
	}b[n+5];
	struct station
	{
		int w;//Õ¾Íâ 
		int t1;//Õ¾Ìü 
		int rou[10000000000+5];

	}a[m+5];
	for(int j=1;j<=m;j++)
		{
			cin>>a[j].w;
		}
	for(int i=1;i<=n;i++)
		cin>>b[i].num;
		for(int j=1;j<=b[i].num;j++)
		{
			cin>>b[i].sta[j]>>a[j].t1;
			a[b[i].sta[j]].rou[i]=i;
		}
	}
	int start,end;
	for(int i=1;i<=q;i++)
	{
		cin>>start>>end;
		for(int i=1;i<=n;i++)
	{
		{
			if(a[start].rou[i]==1) 
			{
				cnt+=a[start].w;
				if(a[end].rou[i]==1) 
				{
					for(int i=start;i<=end;i++) cnt+=a[i].t1; 	
				}
				                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
				
			}
		}
	}
	cout <<cnt;
	return 0;
}

