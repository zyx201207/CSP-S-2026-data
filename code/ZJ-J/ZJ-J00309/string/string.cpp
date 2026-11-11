#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int h=1,t=n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	while(h!=t){
		if(h==t)break;
		bool flag=false;
		if(c[h]==c[t])flag=true;
		if(a[h]>a[t]){
			a[h]-=a[t];
			if(!flag)ans+=a[t];
			t--;
		}else if(a[h]<a[t]){
			a[t]-=a[h];
			if(!flag)ans+=a[h];
			h++;
		}else{
			if(!flag)ans+=a[h];
			h++,t--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}