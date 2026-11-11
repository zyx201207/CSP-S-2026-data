#include <bits/stdc++.h>
using namespace std;
long long n,a[201100],s;
char ch[210000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>ch[i];
	int l=1,r=n;
	while(l<r)
	{
		if(ch[l]==ch[r])
		{
			if(a[l]>a[r]) a[l]-=a[r],r--;
			  else a[r]-=a[l],l++;
			continue;
		}
		if(a[l]==a[r])
		{
			if(ch[l]==ch[r]) l++,r--;
			  else s+=a[l],l++,r--;
		}
		  else 
		  {
		  	if(a[l]<a[r]) s+=a[l],a[r]-=a[l],l++;
		  	  else s+=a[r],a[l]-=a[r],r--;
		  }
	}
	cout<<s;
}