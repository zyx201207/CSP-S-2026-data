#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
int n,m,mx,ans,a[N];
bool t[N][31];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	queue<int>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]; int x=a[i];
		q.push(i);
		int cnt=0;
		while(x){
			t[i][cnt]+=x&1;
			cnt++; x>>=1;
		}
		mx=max(cnt,mx);
	}
	for(int i=mx;i>=0;i--){
		queue<int>p,mq; mq=q;
		while(!mq.empty()){
			int x=mq.front(); mq.pop();
			if(t[x][i]){
				p.push(x);
			}
		}
		if(p.size()>=m) ans|=(1<<i),swap(q,p);
	}
	cout<<ans;
	/*^_^*/
	return 0;
}

