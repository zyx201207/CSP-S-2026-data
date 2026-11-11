#include<bits/stdc++.h>
#define int long long
using namespace std;                                                                                                                                                                                                
int n,m,s,cnt,maxn=LONG_LONG_MIN,b[500010],c,ans,q;
int a[500010];
bool f;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	int w=a[2]-a[1];
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]==w)
			f=1;
		else{f=0;break;}
	}
	if(f==1){
		int i=1;
		while(m>=c&&i<=n)
		{
			i++;
			cnt+=(a[2]-a[1]);
			c+=cnt;
		}
		cout<<i-1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		q=m;
		for(int j=i-1;j>=1;j--){
			q-=(a[i]-a[j]);
			ans++;
			if(q<0) break;
		}
		if(q>=0) ans+=1;
		maxn=max(maxn,ans);
		ans=0;
	}
	cout<<maxn;
	return 0;
}
/*
My crush is zye.
I love zye.
I want to 99 with zye.
I want to walk in the world with you.
zye,I like you,miss you and love you.
Do you want to be my girl friend? 
I want to sleep with you.
I love you very much.
I love you very much.
I want to 99 with you.
*/