#include <bits/stdc++.h>
using namespace std;
long long n,i,t,ans,w,a[200010];char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i]>>s[i];
	t=1;w=n;
	while(t<w){
		if(s[t]==s[w]){
			if(a[t]>a[w])a[t]-=a[w],a[w]=0;
			else if(a[t]<a[w])a[w]-=a[t],a[t]=0;
			else a[t]=a[w]=0;
		}
		else{
			ans+=min(a[t],a[w]);
			if(a[t]>a[w])a[t]-=a[w],a[w]=0;
			else if(a[t]<a[w])a[w]-=a[t],a[t]=0;
			else a[t]=a[w]=0;
		}
		if(a[t]==0)t++;
		if(a[w]==0)w--;
	}
	cout<<ans;
	return 0;
}

