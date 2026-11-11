#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,cur=0,ans=-1;
ll m,a[N];
bool flagb=1;
struct Box{
	ll val;
	int cnt;
}b[N];
void solve(){
	int d=a[2]-a[1];
	int cnt=0,t=0;
	while(m>=t&&cnt<n){
		m-=t;
		t+=d;
		cnt++;
	}
	cout<<cnt<<endl;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])flagb=0;
	}
	if(flagb){
		solve();
		return 0;
	}
	sort(a+1,a+n+1);
	a[0]=a[1]-1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1])b[++cur].val=a[i];
		b[cur].cnt++;
	}
	for(int i=1;i<=cur;i++){
//		printf("set %d : val = %lld , cnt = %d\n",i,b[i].val,b[i].cnt);
		int t=m,x=i-1;
		int cnt=b[i].cnt;
		while(t>=(b[i].val-b[x].val)*b[x].cnt&&x>=1){
			cnt+=b[x].cnt;
			t-=(b[i].val-b[x].val)*b[x].cnt;
//			printf("111cnt += %d , t = %d\n",b[x].cnt,t);
			x--;
		}
		if(x>=1){
			cnt+=t/(b[i].val-b[x].val);
//			printf("222cnt += %d , t = %d\n",t/(b[i].val-b[x].val),t);
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
