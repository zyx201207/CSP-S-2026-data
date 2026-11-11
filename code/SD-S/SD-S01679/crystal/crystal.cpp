#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x/gcd(x,y)*y)
#define pri priority_queue
using namespace std;
struct node{
	int a=0,b=0;
}a[500005];
int cmp(node x,node y){
	return x.a<y.a;
}
void solve(){
	int n,m;
	node ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
	}
	sort(a+1,a+n+1,cmp);
	int flag=0;
	for(int i=1;i<n;i++){
		a[i].b=a[i+1].a-a[i].a;
		if(a[i].b!=a[i-1].b&&i!=1){
			flag=1;
		}
	}
	if(flag){
		for(int i=1;i<=n;i++){
			node sum;
			for(int j=i;j<=n;j++){
				if(sum.b+(j-i+1)*a[j].b>m){
					break;
				}
				sum.b=sum.b+(j-i+1)*a[j].b;
				sum.a++;
			}
			if(sum.a>ans.a){
				ans=sum;
			}else if(sum.a==ans.a&&ans.b>sum.b){
				ans=sum;
			}
		}
		cout<<ans.a+1;	
	}else{
		int sum=0;
		for(int i=1;i<=n;i++){
			if((i+1)*i/2*a[1].b<=m){
				sum=i;
			}
		}
		cout<<sum;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
