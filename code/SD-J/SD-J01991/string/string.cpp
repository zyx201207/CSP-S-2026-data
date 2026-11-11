#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],b[N];
string s[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long len=0;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i]>>s[i];
		len+=a[i];
	}
	long long l=0,r=n-1,lenl=a[0],lenr=a[n-1],ans=0;
	while(l<r)
	{
		if(lenl<=lenr) 
		{	
			if(s[l]!=s[r])	ans+=a[r]-(lenr-lenl)-b[r];
			b[r]+=a[r]-(lenr-lenl)-b[r];
			l++;
			lenl+=a[l];
		}
		else
		{
			if(s[l]!=s[r])	ans+=a[l]-(lenl-lenr)-b[l];
			b[l]+=a[l]-(lenl-lenr)-b[l];
			r--;
			lenr+=a[r];
		}
		//cout<<b[l]<<" "<<b[r]<<" "<<lenl<<" "<<lenr<<" "<<l<<" "<<r<<"\n";
	}
	cout<<ans;
	return 0;
}

//#include<bits/stdc++.h>
//using namespace std;
//const int N=2e5+10;
//int n,a[N];
//string s[N],s0="";
//int main()
//{
//	freopen("string5.in","r",stdin);
//	freopen("string5.out","w",stdout);
//	cin>>n;
//	long long len=0;
//	for(int i=0;i<n;i++)
//	{
//		cin>>a[i]>>s[i];
//		len+=a[i];
//		for(int j=0;j<a[i];j++) s0+=s[i];
//	}
//	long long ans=0;
//	for(long long i=0;i<(len+1)/2;i++)
//	{
//		if(s0[i]!=s0[len-i-1]) ans++;
//	}
//	cout<<ans;
//	return 0;
//}
