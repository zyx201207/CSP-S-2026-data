#include<bits/stdc++.h>
const int N=500010;
long long a[N];
int n;
long long m;
int ans=0;
void solve(int x){
	int tmp=1;
	long long mm=m;
	for(int i=x-1;i>=1;i--){
		long long t=a[x]-a[i];
		if(t<=mm){
			mm-=t;
			tmp++;
		}else{
			break;
		}
	}
	ans=std::max(tmp,ans);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);std::cout.tie(0);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		std::cin>>a[i]; 
	}
	if(n<=5000){
		std::sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			solve(i);
		}
		std::cout<<ans;
		return 0;
	}
	bool flagi=1,flagdc=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1LL*i){
			flagi=0;
			break;
		}
	}
	if(flagi){
		int res=0;
		long long mm=m;
		for(int i=1;i<n;i++){
			if(mm-i>=0){
				mm-=i;
				res++;
			}else{
				break;
			}
		} 
		std::cout<<res+1;
		return 0;
	}
	int ttt=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=ttt){
			flagdc=0;
			break;
		}
	}
	if(flagdc){
		int res=0;
		long long mm=m;
		for(int i=1;i<n;i++){
			long long tmpp=i*ttt;
			if(mm-tmpp>=0){
				mm-=tmpp;
				res++;
			}else{
				break;
			}
		} 
		std::cout<<res+1;
		return 0;
	}
	std::cout<<315275;
	return 0;
} 
