#include<bits/stdc++.h>
using namespace std;
long long n,m,a[222222],cnt[66],k,ans,vv[66];
void js(){
	for(int i=1;i<=n;i++){bool f=1;
		for(int j=0;j<=60;j++){
			if(vv[j]&&(a[i]/(1ll<<j))%2==0){
				f=0;
				break;
			}
		}
		if(f==0)continue;
		k=a[i];
		int t=0;
		while(k){
			cnt[t]+=(k%2);
			k/=2;
			t++;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k=a[i];
		int t=0;
		while(k){
			cnt[t]+=(k%2);
			k/=2;
			t++;
		}
	}
	for(int i=60;i>=0;i--){
		if(cnt[i]>=m){
			for(int j=0;j<=60;j++)cnt[j]=0;
			vv[i]=1;
			js();
			ans+=(1ll<<i);
		}
	}
	cout<<ans;
}
/*AK!!AC!!*/