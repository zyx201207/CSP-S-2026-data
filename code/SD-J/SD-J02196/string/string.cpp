#include<bits/stdc++.h>
#define int long long
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x/gcd(x,y)*y)
using namespace std;
struct node{
	int a;
	char b;
};
node a[200005],b[200005];
void solve(){
	int n,sum=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		char c;
		cin>>t>>c;
		a[i].a=t;
		a[i].b=c;
		b[n-i+1].a=t;
		b[n-i+1].b=c;
		sum+=t;
	}
	sum=(sum+1)/2;
	int cnt1=1,cnt2=n;
	while(1){
		if(sum<=0){
			break;
		}
		if(a[cnt1].b==a[cnt2].b){
			if(a[cnt1].a>a[cnt2].a){
				sum-=a[cnt2].a;
				a[cnt1].a=a[cnt1].a-a[cnt2].a;
				cnt2--;
			}else if(a[cnt1].a<a[cnt2].a){
				sum-=a[cnt1].a;
				a[cnt2].a=a[cnt2].a-a[cnt1].a;
				cnt1++;
			}else{
				sum-=a[cnt1].a;
				cnt1++;
				cnt2--;
			}
		}else{
			if(a[cnt1].a>a[cnt2].a){
				sum-=a[cnt2].a;
				ans+=a[cnt2].a;
				a[cnt1].a=a[cnt1].a-a[cnt2].a;
				cnt2--;
			}else if(a[cnt1].a<a[cnt2].a){
				sum-=a[cnt1].a;
				ans+=a[cnt1].a;
				a[cnt2].a=a[cnt2].a-a[cnt1].a;
				cnt1++;
			}else{
				sum-=a[cnt1].a;
				ans+=a[cnt1].a;
				cnt1++;
				cnt2--;
			}
		}
		if(cnt1>=cnt2){
			break;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

