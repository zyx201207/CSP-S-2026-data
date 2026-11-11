#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,ans;
long long m,a[N],c[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	c[1]=a[2]-a[1];
	if(c[1]>=m)
		{
			cout<<c[1]<<endl;
			return 0;
		}
	for(int i=2;i<n;i++){
		c[i]=((a[i+1]-a[i])*i)+c[i-1];
		if(c[i]>=m)
			{	
				while(c[i+1]==c[i])
				{
					i++;
				}
				cout<<i+1<<endl;
				return 0;
			}
	}
	cout<<0<<endl;
	return 0;
}

