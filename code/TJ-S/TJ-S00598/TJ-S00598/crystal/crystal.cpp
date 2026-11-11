#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,m2,sum=1;
	cin>>n>>m;
	m2=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(m2>=abs(a[i+1]-a[i]))
		{	
			if(a[i]==a[i-1])
			{
				if(m2>=abs(a[i-1]-a[i+1]))
				{
					sum++;
					m2-=abs(a[i-1]-a[i+1]);
					a[i-1]=a[i+1];
				}
				else{
					sum++;
					break;
				}
			}
			else{
				m2-=abs(a[i+1]-a[i]);
				a[i]=a[i+1];
				sum++;
			}	
		}
		else{
			break;
		}
	}
	cout<<sum;
	return 0;
}
