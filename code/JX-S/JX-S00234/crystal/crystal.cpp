#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500086],s=1,began;
long long lxy(long long x)
{
	long long ji=0;
	for(long long i=began;i<=n;i++)
	{
		if(a[i]==a[began])ji++;
		else break;
	}
	int mark=a[began]-a[began-1];
	int ha=x/mark;
    return max(ha+ji,s);
}
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int q=a[2]-a[1];
	for(long long i=1;i<=n;i++)
	if(a[i]-a[i-1]==q&&i>=2) ans++;
	//cout<<ans<<" "<<n<<endl;
		if(ans==n-1){
		for( long long i=1;i<=n;i++)
		{
			if(m-i*q>0) m=m-i*q;
			else {cout<<i;
				return 0;}
		}
		cout<<n;
	}
	for(long long i=2;i<=n;i++)
	{
		if (a[i]==a[1]) s++;
		else {began=i;break;}
	}
	
	for(long long zxy=m;zxy>=1;zxy--)
	{
		if(zxy>s)
		{
			zxy=zxy+1-s;
			for(long long i=1;i<=s;i++)
			{a[i]++;}
		}
		else {cout<<lxy(zxy);return 0;}
		s=1;
			for(long long i=2;i<=n;i++)
	        {
		if (a[i]==a[1]) s++;
		else {began=i;break;}
	        }
	}
	return 0;
}

