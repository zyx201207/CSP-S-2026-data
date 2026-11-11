#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,i,j;
int w=0,a[500001];
int pan()
{
	for(k=1;j+k-1<n;k++)
    {
    	
	for(i=k;i<=j+k-1;i++)
		w+=a[i];
		
	if((j+w)%j==0)	
	return 1;
    }
    
    return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i]<a[j]) swap(a[i],a[j]);
			
	for(j=n;j>=1;j--)
		if(pan()==1)
		{
			cout<<j;
			return 0;
		}
	return 0;
}
