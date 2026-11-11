#include<iostream>
using namespace std;

typedef long long ll;
const int N=2e6+5;
ll a[N],cz[N],d;
int n;

bool check(int l,int r){
	for(int i=1;i<=n;i++){
		if(cz[i]>d) return false;
	}
	if(d==2&&(r-l+1)&2){
		return false;
	}
	return true;
}

void solve(){
	int ans=0;
	scanf("%d%lld",&n,&d);
	cz[1]=0;
	for(int i=2;i<=n;i++){
		scanf("%lld",&a[i]);
		cz[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(i!=j){
				if(check(j,i)){
					++ans;
				}
			}
		}
	}
	printf("%d\n",ans);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		solve();
	}
	return 0;
}