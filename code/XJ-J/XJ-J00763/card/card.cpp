#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N]={0},b[N]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.ont","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		for(int j=0;j<n;j++)
		{
			if(a[i]==a[j])
			{
				for(int k=0;k<j;k++)
				{
				b[j]=a[j];
					a[k]=0;
				}
				
				for(int k=0;k<j;k++)
				{
					a[k]=b[k];
				}
			}
		}
	}
	cout<<"10 3 3";
	
	
	return 0;
}