#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
struct Q{
	ll a,b;
};
ll sum[35]={1},n,m,a[N],maxn=0,ans;
Q b[N];
bool cmp(Q a,Q b){
	if(a.a!=b.a) return a.a>b.a;
	return a.b>b.b;
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	for(int i=1;i<=30;i++){
		sum[i]=sum[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		b[i].b=a[i];
	}
	for(int i=30;i>=0;i--){
		for(int j=1;j<=n;j++){
			if(a[j]>=sum[i]){
				a[j]-=sum[i];
				b[j].a++;
			}
		}
	}
	sort(b+1,b+n+1,cmp);
	if(m==1){
		cout<<maxn;
		return 0;
	}
	ans=b[1].b;
	for(int i=2;i<=m;i++){
		ans=ans&b[i].b;
	}
	cout<<ans;
	return 0;
}
