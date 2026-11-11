#include<bits/stdc++.h>
using namespace std;
long long int n,m,z[200200],a[200200],k,l,da,kk;
string s1,s2;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	k=a[n];
	while(k) {l++;k/=2;}
	for(int i=l;i>=0;i--)
	{
		kk=0;
		for(int j=1;j<=n;j++)if(a[j]/int(pow(2,i))%2&&!z[j])kk++;
		if(kk>=m)
		{
			da+=int(pow(2,i));
			for(int j=1;j<=n;j++) if(a[j]/int(pow(2,i))%2==0 && !z[j])z[j]=1;
		}
	}
	cout<<da;
}
