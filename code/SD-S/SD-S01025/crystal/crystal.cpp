#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N],ans,m;
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	ll last=1,mex=a[1],nowm=m,len=1,ans=1;
	for(int i = 2;i<=n;i++){
		if(a[i]>mex){
			ll now=a[i]-mex;
			ll now1=now*len;
			if(now1>nowm){
				while(last<i){
					ll op=mex-a[last];
					nowm+=op;
					now1-=now;
					len--;
					last++;
					if(nowm>=now1){
						break;
					}
					
				}
				if(nowm>=now1){
					mex=a[i];
					nowm-=now1;
					len++;
				}else{
					mex=a[i];
					len=1;
					nowm=m;
					last=i;
				}
			}else{
				mex=a[i];
				nowm-=now1;
				len++;
			}
		}else{
			len++;
			
		}
		ans=max(len,ans);
	}
	printf("%lld",ans);
	return 0;
} 
