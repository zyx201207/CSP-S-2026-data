#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
int n;
const int N=2e5+10;
string s;
ll a[N];
char c[N];
ll ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	ll len=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
	} 
	int begin=1,end=n;
	bool f=false;
	ll sum=len/2;
	int cnt=0;
//	cout<<begin<<" "<<end<<"\n";
	while(!f)
	{
		if(cnt==3) break;
		cnt++;
		if(sum-a[begin]<0)
		{
			ll ab=a[begin];
			ll p=ab-sum;
			if(ab==2&&len%2!=0) ans++;
			else if(sum>p)
			{
			//	ll k=a[++begin];
				if(c[begin]!=c[++begin]) ans+=sum-p;
	
			}
			break;	
		}
		else sum-=a[begin];
		if(a[begin]<a[end]) 
		{
			if(c[begin]!=c[end]){
				ans+=a[begin];
			}
			a[end]-=a[begin];
			begin++;
		}
		else if(a[begin]==a[end])
		{
			if(c[begin]!=c[end]){
				ans+=a[begin];
			}
			begin++;end--;
		}
		else if(a[begin]>a[end])
		{
			if(c[begin]!=c[end])
			{
				ans+=a[end];
			}
			a[begin]-=a[end];
			bool flag=false;
			while(!flag){
				end--;
				if(a[begin]>a[end])
				{
					if(c[begin]!=c[end]) ans+=a[end];
					a[begin]-=a[end];
				}
				else if(a[begin]<=a[end])
				{
					if(c[begin]!=c[end]) ans+=a[begin];
					a[end]-=a[begin];
					if(a[end]==0) end--;
					flag=true;
				}
			}
			begin++;
		}	
	}
//	cout<<cnt<<"\n";
	cout<<ans;
	return 0;
} 
