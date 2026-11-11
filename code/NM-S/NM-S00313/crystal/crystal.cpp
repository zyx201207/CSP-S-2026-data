#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],h,pjz,cnt,ans=1,b[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    bool v=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		h+=a[i];
		if(a[i]!=a[i+1]) v=0;
	}
    if(v==1) {cout<<n;return 0;}
    for(int i=1;i<=n;i++)
    		b[i]=abs(a[i]-n);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		if(cnt+b[i]>m) {cout<<ans;return 0;}
		else{cnt+=b[i];ans++;}
	}
    cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
