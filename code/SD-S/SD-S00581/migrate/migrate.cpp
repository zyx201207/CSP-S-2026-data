#include <iostream>
#include <algorithm>
#include <climits> 
#include <cmath>
using namespace std;
const int N = 2e6+1;
int c,t;
int n,d;
long long pos[N];
long long ans = 0;


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans = 0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&pos[i]);
		}
		sort(pos+1,pos+1+n);
		
		if(c==11 || c==12){
			long long gap = pos[2]-pos[1];
			if(d<gap) ans = 0;
			else {
				int ava = 0;
				for(int i=1;i<=n;i++){
					ava++;
					if(ava>2) break;
				}
				if(ava==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

