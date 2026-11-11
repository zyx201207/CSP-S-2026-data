#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char str[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	long long s=0,ans=0,l=0,r=0;
	cin>>a[0]>>str[0];
	for(int i=1;i<n;i++)
	{
		cin>>a[i]>>str[i];
		s+=a[i];
		if(str[i]==str[i-1])
			a[i-1]+=a[i],i--,n--;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0,j=n-1;r<s/2||l<s/2;)
	{
		if(str[i]==str[j])
		{
			if(a[i]>a[j])
				a[i]-=a[j],j--,r+=a[j+1];
			else if(a[i]==a[j])
				i++,j--,r+=a[j+1],l+=a[i-1];
			else a[j]-=a[i],i++,l+=a[i-1];
		}
		else {
			if(a[i]>a[j])
				a[i]-=a[j],j--,ans+=a[j+1],r+=a[j+1];
			else if(a[i]==a[j])
				i++,j--,ans+=a[i-1],r+=a[j+1],l+=a[i-1];
			else a[j]-=a[i],i++,ans+=a[i-1],l+=a[i-1];
		}
	}
	cout<<ans;return 0;
}
