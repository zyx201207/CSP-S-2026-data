//孟梓瑜 SN-J00834 西安市铁一中学 
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const long long Maxn=200005ll;
//struct node
//{
//	ll gs;
//	char zf;	
//};
ll a[Maxn];
char c[Maxn];
char sz[Maxn];
//node nwe[Maxn];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ll n,he,ans;
	cin>>n;
	for(ll i=1ll;i<=n;i++)
		cin>>a[i]>>c[i],he+=a[i];
	int idx=1ll;
	for(int i=1ll;i<=n;i++)
	{
		for(int j=idx;j<=idx+a[i]-1;j++)
			sz[j]=c[i];
		idx+=a[i];
	}
//	cout<<idx<<endl;
	for(int i=1;i<=(idx-1)/2ll;i++)
	{
//		cout<<sz[i];
		ans+=(sz[i]!=sz[idx+1ll-i]);
	}
	cout<<ans-1ll;
		
	
//	if(he%(2ll)==1ll)
//	{
//		ll zd=he/(2ll)+1ll;
//		ll idx=1;//此刻该填第几位了 
//		ll tzy=n;
//		ll wji=1;//对于外界，现在的i应该是多少 
//		for(int i=1;i<=tzy;i++)//这里的i是适用于nwe的 
//			if(idx<zd&&idx+a[wji]<zd)//还没填到
//				nwe[i].gs=a[wji],nwe[i].zf=c[wji],idx+=a[wji],wji++;
//			else if(idx==zd)
//				nwe[i].gs=1ll,nwe[i].zf=c[wji],i++,tzy++,nwe[i].gs=a[wji]-1ll,nwe[i].zf=c[wji],idx+=a[wji],wji++;
//			else if(idx<zd&&idx+a[wji]>zd)
//				nwe[i].gs=zd-idx,nwe[i].zf=c[wji],i++,tzy++,nwe[i].gs=1ll,nwe[i].zf=c[wji],i++,tzy++,nwe[i].gs=a[wji]-nwe[i-2].gs-1ll,nwe[i].zf=c[wji],idx+=a[wji],wji++;
//			else if(idx+a[wji]==zd)
//				nwe[i].gs=a[wji]-1ll,nwe[i].zf=c[wji],i++,tzy++,nwe[i].gs=1ll,nwe[i].zf=c[wji],idx+=a[wji],wji++;
//			else if(idx>zd)
//				nwe[i].gs=a[wji],nwe[i].zf=c[wji],idx+=a[wji],wji++;
//		for(int i=1;i<=tzy;i++)
//			cout<<nwe[i].gs<<" "<<nwe[i].zf<<"\n";
//	}
//	else
	
	return 0;
}
