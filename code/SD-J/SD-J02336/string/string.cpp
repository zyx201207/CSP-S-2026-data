#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0,ans=0;
long long x[200010],qs[200010],js[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
		qs[i]=ans+1;
		ans+=x[i];
		js[i]=ans;	
	}
	if(ans%2==0){
		for(int i=1;i<=ans/2;i++){
		char q,h;
		for(int j=1;j<=n;j++){
			if(qs[j]<=i&&js[j]>=i){
				q=c[j];
			}
			if(qs[j]<=ans-i+1&&js[j]>=ans-i+1){
				h=c[j];
				break;
			}
		}
		if(q!=h){
			cnt++;
		}
	}
	}
	else{
		for(int i=1;i<=(ans-1)/2;i++){
		char q,h;
		for(int j=1;j<=n;j++){
			if(qs[j]<=i&&js[j]>=i){
				q=c[j];
			}
			if(qs[j]<=ans-i+1&&js[j]>=ans-i+1){
				h=c[j];
				break;
			}
		}
		if(q!=h){
			cnt++;
		}
	}
	}	
	printf("%lld",cnt);
	return 0;
}
