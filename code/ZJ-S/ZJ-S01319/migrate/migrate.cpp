#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d,x[2000001];
int cnt[5001];
int T[5001];
struct stu{
	int u,t;
};
void sp_(){
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof cnt);
		memset(T,0,sizeof T);
		queue<stu>q;
		q.push({i,0});
		while(!q.empty()){
			stu v=q.front();
//			cout<<v.u<<'&'<<v.t<<'\n';
			q.pop();
			for(int j=v.u+1;j<=n&&x[v.u]+d>=x[j];j++){
				if(cnt[j]>=3)continue;
				if(T[j]!=0&&v.t+1!=T[j])continue;
				cnt[j]++;
				T[j]=v.t+1;
				q.push({j,v.t+1});
			}
		}
		for(int j=i+1;j<=n;j++){
//			cout<<i<<','<<j<<':'<<cnt[j]<<'\n';
			if(cnt[j]==2)ans++;
		}
	}
	cout<<ans<<'\n';
	return;
}
void spA(){
	int c=x[2]-x[1];
	if(d<2*c){
		cout<<0<<'\n';
		return;
	}
	int b=d/c;
	cout<<max(n-b-b+1,0LL)<<'\n';
}
void spB(){
	int ans=0;
	int num=0;
	for(int i=1;i<=n;i++){
		if(x[i]-x[1]<=d&&x[n]-x[i]<=d)num++;
		if(num>2){
			cout<<0<<'\n';
			return;
		}
	}
	if(num<=1){
		cout<<0<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		int l=i+1,r=n,mid,sum;
		while(l<=r){
			mid=(l+r)/2;
			if(x[mid]-x[i]<=d){
				l=mid+1;
				sum=mid;
			}else{
				r=mid-1;
			}
		}
		ans+=n-sum;
	}
	cout<<ans<<'\n';
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==11||c==12){
			spA();
		}else if(c==13||c==14){
			spB();
		}else{
			sp_();
		}
	}
	return 0;
}
