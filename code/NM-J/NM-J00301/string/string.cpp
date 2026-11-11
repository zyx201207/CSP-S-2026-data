#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll cnt[N];char chr[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	ll sum=0;
	for(int i=1;i<=n;++i){
		cin>>cnt[i]>>chr[i];
		sum+=cnt[i];
	}
	ll tst=0;
	for(int i=1;i<=n;++i){
		tst+=cnt[i];
		if(tst>n){
			tst=i;
			break;
		} 
	}
	int stt=1,lst=n;
	ll ans=0;
	while(stt<=lst){
		if(cnt[stt]>cnt[lst]){
			if(chr[stt]!=chr[lst]){
				ans+=cnt[lst];
			}
			cnt[stt]-=cnt[lst];
			--lst;
		}else if(cnt[stt]<cnt[lst]){
			if(chr[stt]!=chr[lst]){
				ans+=cnt[stt];
			}
			cnt[lst]-=cnt[stt];
			++stt;
		}else{
			if(chr[stt]!=chr[lst]){
				ans+=cnt[lst];
			}
			cnt[lst]=0;cnt[stt]=0;
			++stt;--lst;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
