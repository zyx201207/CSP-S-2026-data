#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define se second
#define fi first
using namespace std;
const int N=2e5+5;
ll n,m,a[N],sum=0;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll y=0,z=0;
	for(int i=1,j=n;i<j;)
	{
		if(c[i]!=c[j])
		{
//			cout<<a[i]<<" "<<a[j]<<" ";
			sum+=min(a[i],a[j]);
		}
//		cout<<sum<<" "<<i<<" "<<j<<endl;
		if(a[i]==a[j])
		{
			i++,j--;
		}
		else if(a[i]>a[j]){
			a[i]-=a[j];
			j--;
		}
		else {
			a[j]-=a[i];
			i++;
		}
		
	}
	cout<<sum;
	return 0; 
}

