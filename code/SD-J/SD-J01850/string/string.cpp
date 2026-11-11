#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+10;
int n,sum=0,ans;
struct aaa{
	int a;
	char s;
}h[N];
signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i].a>>h[i].s;
		sum+=h[i].a;
	}
	int l=1,r=sum;
	int pl=1,pr=n;
	while(l<r&&pl<pr){
		int minl=min(h[pl].a,h[pr].a);
		if(h[pl].s!=h[pr].s){
			ans+=minl;
		}
		l+=minl;
		r-=minl;
		int ypl=pl,ypr=pr;
		if(minl==h[pl].a){
			pl++;
			if(minl==h[pr].a){
				pr--;
			}
		}
		else{
			pr--;
		}
		h[ypl].a-=minl,h[ypr].a-=minl;
	}
	cout<<ans;
	return 0;
}

