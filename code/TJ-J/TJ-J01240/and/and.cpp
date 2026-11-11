#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cnt[200005],ans;
bool vst[200005];
long long pw(long long y){
	if(y==0)return 1;
	long long ans=1;
	for(int i=1;i<=y;i++){
		ans*=2;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long u=a[i],js=0;
		while(u){
			cnt[js++]+=(u&1);
			u>>=1;
		}
	}
	for(int i=31;i>=0;i--){
		if(cnt[i]>=m){
			ans+=pw(i);
			for(int j=1;j<=n;j++){
				if(!vst[j]&&((a[j]>>i)&1)==0){
					vst[j]=1;
					long long u=a[j],js=0;
					while(u){
						cnt[js++]-=(u&1);
						u>>=1;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
