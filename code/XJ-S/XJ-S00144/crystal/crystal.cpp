#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef string str;
typedef double dou;
const int N=5e5;
uint n;
ull m;
ll a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		uint j=i-1;
		uint sum=abs(a[i]-a[j])*j;
		if(sum>m){
			cout<<j;
			return 0;
		}
		m-=sum;
	}
	cout<<n;
	return 0;
} 
