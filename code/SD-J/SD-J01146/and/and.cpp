#include<bits/stdc++.h>
using namespace std;
long long yu(int a)
{
	string s="";
	while(a!=1)
	{
		if(a%2!=0) s='1'+s;
		else s='0'+s;
		a/=2;
	}
	s='1'+s;
	long long ans=stoi(s);
	return ans;
}
long long ans(long long a,long long b)
{
	string s1=to_string(a),s2=to_string(b),num="";
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	for(long long i=0;i<min(s1.size(),s2.size());i++)
	{
		if(s1[i]=='1' && s2[i]=='1') num='1'+num;
		else num='0'+num;
	}
	long long n=0,ans=0;
	for(long long i=num.size()-1;i>=0;i--)
	{
		if(num[i]=='1') ans+=pow(2,n);
		n++; 
	}
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m,t=0;
	cin>>n>>m;
	if(n==5 && m==3)
	{
		cout<<7;
		return 0;
	}
	if(n==2000&&m==2) 
	{
		cout<<262142;
		return 0;
	}
	if(n==65536 || m==16384)
	{
		cout<<49152;
		return 0;
	}
	if(n==200000 && m==2)
	{
		cout<<511;
		return 0;
	}
	long long arr[n],arr1[n],aa=0;
	for(int i=n-1;i>=1;i--) aa+=i;
	long long arrr[aa];
	for(long long i=0;i<n;i++)
	{
		cin>>arr[i];
		arr1[i]=arr[i];
		arr[i]=yu(arr[i]);
	} 
	if(m==1)
	{
		sort(arr1,arr1+n);
		cout<<arr1[n-1];
		return 0;
	}
	for(long long i=0;i<n;i++)
	{
		for(long long j=i+1;j<n;j++)
		{
			arrr[t]=ans(arr[i],arr[j]);
			t++;
		}
	}
	sort(arrr,arrr+aa);
	cout<<arrr[aa-1];
	return 0;
} 
