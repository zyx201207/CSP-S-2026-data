#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010],n,t,w,ans;
char ch[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)	
		cin>>a[i]>>ch[i];
	t=1;w=n;
	while(t<w){
		if(a[t]>a[w]){
			if(ch[t]==ch[w]) a[t]-=a[w],w--;
			else ans+=a[w],a[t]-=a[w],w--;
		}
		else if(a[t]<a[w]){
			if(ch[t]==ch[w]) a[w]-=a[t],t++;
			else ans+=a[t],a[w]-=a[t],t++;
		}
		else{
			if(ch[t]==ch[w]) t++,w--;
			else ans+=a[w],t++,w--;
		}
	}
	cout<<ans;
	return 0;
}