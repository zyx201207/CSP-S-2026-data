#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,ans=-1;
struct s{
	ll n,cnt;
}a[N];
bool cmp(s a,s b){
	return a.n<b.n;
}
void slove(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].n;
		a[i].cnt=1;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++){
		int c=a[i-1].cnt*(a[i].n-a[i-1].n);
		if(m>=c){
			a[i].cnt+=a[i-1].cnt;
			m-=c;
			ans=max(a[i].cnt,ans);
		}else break;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int q,t=1;
//	cin>>q>>t;
	while(t--){
		slove();
	}
	return 0;
} 