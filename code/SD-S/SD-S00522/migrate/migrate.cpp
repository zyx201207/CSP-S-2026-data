#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[200010],x,x2,ans;
int qdis(int u,int v) {
	int now=u,cnt=0;
	while(now!=v) {
		if(now+d>=v) {
			now=v;
			continue;
		}
		int l=now,r=v;	
		for(int i=l;i<=r;i++){
			if(a[i]<=a[now]+d&&a[i+1]>a[now]+d){
				l=i;
				break;
			}
		}
		if(now==u) x=l;
		now=l;
		cnt++;
	}
	return cnt;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		ans=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=1; i<=n; i++) {
			for(int j=i+3; j<=n; j++) {
				int cntmin=qdis(i,j);
				x2=x;
				int cnt1=qdis(x2-1,j)+1;
				int cnt2=qdis(x2-2,j)+1;

				if(cnt1==cntmin&&cnt2!=cntmin){
					ans++;
				}
			}
		}
		cout<<ans;	
	}
	return 0;
}

