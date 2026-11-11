#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,c,t,h[333],w[333];
ll d,x[2001000],s[2001000],ss[2001000];

bool check(int l,int r){
	for(int i = l;i < r;i++){
		if(x[i + 1] - x[i] > d){
			return 0;
		}
	}
	ll nw = 0;
	int cnt = 0;
	for(int i = 1;i <= n;i++)h[i] = w[i] = 0;
	for(int i = l;i < r;i++){
		if(nw + x[i + 1] - x[i] > d){
			nw = x[i + 1] - x[i];
			h[++cnt] = i;
		}else{
			nw += x[i + 1] - x[i];
		}
	}
	cnt = 0;
	nw = 0;
	for(int i = r;i > l;i--){
		if(nw + x[i] - x[i - 1] > d){
			nw = x[i] - x[i - 1];
			w[++cnt] = i;
		} else{
			nw += x[i] - x[i - 1];
		}
	}
	int cn = 0;
	if(l == 1 && r == 4){
	//	printf("--%d %d %d\n",l,r,cnt);
		for(int i = 1;i <= cnt;i++){
	//		printf("*%d %d\n",w[i],h[i]);
		}
	}
	for(int i = 1;i <= cnt;i++){
		cn += abs(w[cnt - i + 1] - h[i]);
	}
	return cn == 1;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(;t--;){
		scanf("%d",&n);
		scanf("%lld",&d);
		for(int i = 1;i <= n;i++){
			scanf("%lld",&x[i]);
		}
		if(n <= 300){
			int ans = 0;
			for(int i = 1;i <= n;i++){
				for(int j = i;j <= n;j++){
				//	int t = ans;
					ans += check(i,j);
				//	if(t != ans){
				//		printf("%d %d\n",i,j);
				//	}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}