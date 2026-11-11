#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],vlen,ans;
char c[200005];
vector<long long>vt; 
vector<char>ct;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	} 
	long long total=0;
	char ch=c[1];
	for(int i=1;i<=n;i++)
	{
		vlen+=a[i];
		if(c[i]==c[i+1])
		{
			total+=a[i];
		}
		else
		{
			total+=a[i];
			vt.push_back(total);
			ct.push_back(ch);
			ch=c[i+1];
			total=0;
		}
	}
	long long len=vt.size();
	long long left=0,right=len-1,l=1,r=vlen;
/*	while(l<r)
	{
	//	cout<<left<<" "<<right<<endl;
		if(ct[left]!=ct[right]) ans++;
		l++;
		r--;
	//	cout<<l<<" "<<(vlen-r-1)<<endl;
		if(l>=vt[left]) left++;
		if((vlen-r-1)>=vt[right]) right--;
	}*/
	while(l<r&&left<right)
	{
		if(ct[left]!=ct[right]) ans+=min(vt[left],vt[right]);
		l+=min(vt[left],vt[right]);
		r-=min(vt[left],vt[right]);
		vt[left]-=min(vt[left],vt[right]);
		vt[right]-=min(vt[left],vt[right]);
		if(vt[right]==0) right--;
		if(vt[left]==0) left++;
		
	}
	cout<<ans<<endl;
	return 0;
} 
/*
plplaaaa
l a
*/
