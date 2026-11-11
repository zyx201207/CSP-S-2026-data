#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,a;
cin>>n>>a;
bool q[50]={0};
int pp[50]={0};
for(int i=0;i<n;i++)
{
	cin>>pp[i];
	q[pp[i]]=1;
}
int h[50]={0};
int f[50]={0};
for(int i=0;i<n;i++)
{
	h[i]=pp[i];
	for(int j=0;j<i;j++)
	{
		if(h[i]==h[j])
		{
			for(int z=j;z<i;z++)
			{
				h[z]=0;
			}
		 } 
	}
    for(int j=0;j<n;j++)
    {
    	if(h[j]!=0)
    	{
    		f[h[j]]++;
		}
	}
}
for(int i=0;i<50;i++)
{
	if(q[i]==1)cout<<f[h[i]]<<" ";
}
	return 0;
}
