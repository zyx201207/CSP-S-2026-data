#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,a[200010],ans,mi,t,w;
char s[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i]>>s[i];
	t=1;w=n;
	while(t<w){
		mi=min(a[t],a[w]);
		if(s[t]!=s[w])ans+=mi;
		a[t]-=mi;a[w]-=mi;
		if(!a[t])t++;
		if(!a[w])w--;
	}
	cout<<ans;
	return 0;
}

