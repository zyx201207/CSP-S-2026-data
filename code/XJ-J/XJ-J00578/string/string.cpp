#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
char c[N],str[N];
string s;
long long int n,a[N],cnt[N],cnt2[N],sum,t,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	t=n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		cnt[c[i]]+=a[i];
	}
	for(int i=0;i<n;i++){
		if(cnt[c[i]]==sum){
			cout<<'0';
			return 0;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==a[t]&&c[i]==c[t]) continue;
		if(a[i]==a[t]&&c[i]!=c[t]){
			ans+=a[i];
			a[t]=a[i],c[t]=c[i];
			t--;
		}
		if(a[i]!=a[t]&&c[i]!=c[t]){
			ans+=a[i];
			if(a[i]<a[t]){
				a[i]=a[t]-a[i];
				c[i]=c[t];
			}
			if(a[i]>a[t]){
				a[t]=a[i]-a[t];
				c[t]=c[i];
			}
			t--;
		}
	}
	cout<<ans;
	return 0;
}