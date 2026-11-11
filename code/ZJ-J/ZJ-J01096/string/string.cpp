#include <bits/stdc++.h>
#define int long long
using namespace std;
int i,n,a[1000001],s,t,w,ans;
char b[1000001];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s+=a[i];
	}
	t=1;w=n;
	while(t<=w){
		if(t==w){
			if(a[t]%2==1) ans+=a[t]-1;
			else ans+=a[t];
			break;
		}
		if(b[t]==b[w]) ans+=min(a[t],a[w])*2;
		if(a[t]<a[w]) a[w]-=a[t],t++;
		else if(a[t]>a[w]) a[t]-=a[w],w--;
		else t++,w--;
	}
	cout<<(s-ans)/2;
	return 0;
}

