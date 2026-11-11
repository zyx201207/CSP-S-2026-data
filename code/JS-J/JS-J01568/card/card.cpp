#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int a1[500005]={-1};
int b[300005];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);    
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
    {
		int h=0;
		for(int j=i;j<=n;j++)
		{
			int k=1;
			while(a1[k]!=-1)
			{
				if(a1[k]==a[j])
				{
					int l=k+1;
				    while(a1[l]!=-1)
				    {
						h--;
					    a1[l]=-1;
					    l++;	
					}
					break;
				}
				k++;
			}
		    a1[h+1]=a[j];	
		}
		for(int j=1;j<=h;j++)
		{
		    b[a1[j]]++;
		    a1[j]=-1;
	    }
	    
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
    return 0;	
}



