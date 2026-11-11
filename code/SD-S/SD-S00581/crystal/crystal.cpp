#include <iostream>
#include <algorithm>
using namespace std;
const int N = 500000+5;
long long n,m;
long long crystals[N];
long long delta[N];
long long ans = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&crystals[i]);
	}
	sort(crystals+1,crystals+1+n);
	for(int i=1;i<=n;i++){
		delta[i] = crystals[i]+delta[i-1];

	}
	//不含l，假设r为基准（最大） 
	long long l=0,r=1,cost = 0;
	for(;l<=n;){
		//cout << l  << ' ' << r <<' ' << cost << endl;
		
		if(cost<=m) ans = max(ans,r-l);
		
		if(l==r&&r+1<=n){  //强制扩展 
			r++;
			cost = crystals[r]*(r-l)-(delta[r]-delta[l]);
		}
		if(r+1<=n){
			if(crystals[r+1]*(r-l+1)-(delta[r+1]-delta[l])>m){
				l++;
				cost = crystals[r]*(r-l)-(delta[r]-delta[l]);
				
			} else {
				r++;
				cost = crystals[r]*(r-l)-(delta[r]-delta[l]);
				
			}
		} else { //强制收缩 
			l++;
			cost = crystals[r]*(r-l)-(delta[r]-delta[l]);
		}
	}
	printf("%lld",ans);
	
	return 0;
}

