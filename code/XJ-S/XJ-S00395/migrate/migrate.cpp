#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int arr[N];
int dao[N];
int ji[N];
int n,d;
void sd(int x,int y,int setp)
{
	if(arr[y]-arr[x]<=d)
	{
		ji[setp]++;
		return ;
	}
	for(int a=x+1;a<y;a++)
	{
		if(arr[a]-arr[x]<=d)
			sd(a,y,setp+1);
	}
}
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		int ans=0;
		for(int a=0;a<n;a++)
			cin>>arr[a];
		for(int a=0;a<n-1;a++)
			for(int b=a+1;b<n;b++)
			{
				sd(a,b,1);
				for(int i=1;i<n;i++)
					if(ji[i])
					{
						if(ji[i]==2)
						{
							ans++;
							break ;
						}
						else
							break ;
					}
				for(int i=1;i<n;i++)
					ji[i]=0;
			}		
		cout<<ans<<endl;
	}
	
	
	return 0;
} 
