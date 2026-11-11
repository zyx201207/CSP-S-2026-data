#include<bits/stdc++.h>
using namespace std;
//#define ll long long
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int c,t,cnt=0;
	long long n,d,isl[1000000005];
	cin>>c>>t;
	for(int g=1;g<=t;g++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>isl[i];
			for(int x=1;x<=n;x++)
			{
				for(int y=x;y<=n;y++)
				{
					if((y-x)/d==1) cnt++;
				}
			}
		}
		cout <<cnt<<endl;
		
	}

	return 0;
}

