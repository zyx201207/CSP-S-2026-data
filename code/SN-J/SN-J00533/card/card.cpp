#include <bits/stdc++.h>
using namespace std;
int u[50005];
int e[50005];
int f[30005];
int main()
{
//	freopen("card.in";"r";stdin);
 //   freopen("card.out";"w";stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>u[i];
	}
	for(int i=1;i<=n;i++){
		f[u[i]]++;
        for(int v=i+1;v<=n;v++)
		{
        	if(u[v]==0){
        			u[v]=e[v];
			}
            if(u[v]==u[i])
			{
        		for(int a=v;a>=1;a--)
				{
        			e[a]=u[a];
        			u[a]=0;
				}
			}
			f[u[v]]++;
		}
	}
	for(int i=1;i<=m;i++){
    	cout<<f[i]<<" ";
	}
}
