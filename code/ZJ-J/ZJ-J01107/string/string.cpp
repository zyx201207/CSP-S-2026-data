#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,i,s,t,w,ans,bao,mid,a[200010],c[200010];
char b[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(i=1;i<=n;i++)c[i]=c[i-1]+a[i];
	s=(c[n]+1)/2;
	t=1;w=n;bao=1;
	while(t<=w){
		mid=(t+w)/2;
		if(c[mid]==s){
			bao=mid;break;
		}
		else if(c[mid]<s)t=mid+1;
		else bao=mid,w=mid-1;
	}
	t=1;w=n;
	while(t<=w){
		if(a[t]==a[w]){
			if(b[t]==b[w])w--,t++;
			else ans+=a[w],w--,t++;
		}
		else if(a[t]<a[w]){
			a[w]-=a[t];
			if(b[t]==b[w])t++;
			else ans+=a[t],t++;
		}
		else{
			a[t]-=a[w];
			if(b[t]==b[w])w--;
			else ans+=a[w],w--;
		}
	}
	cout<<ans;
}