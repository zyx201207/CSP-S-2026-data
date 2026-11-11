#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int c,t,n;
long long x[2000005],d;
struct node{
	int val,num;
};
bool check(const int &a,const int &b){
	vector<node>dp(b-a+1,{INF,0});
	dp[0]={0,0};
	dp[1]={1,1};
	for(int i=2;a+i<=b;i++){
		dp[i]={dp[i-1].val+1,1};
		for(int j=i-2;x[a+i]-x[a+j]<=d&&j>=0;j--){
			if(dp[j].val+1<dp[i].val){
				dp[i]={dp[j].val+1,1};
			}
			else if(dp[j].val+1==dp[i].val){
				dp[i].num+=1;
			}
		}
	}
	if(dp[b-a].num==2){
		return true;
	}
	return false;
}
int fid_up(const long long y,int L,int R){
	while(L<=R){
		int mid=(L+R)>>1;
		if(x[mid]>x[y]+d){
			R=mid-1;
		}
		else L=mid+1;
	}
	return R;
}
int fid_down(const long long y,int L,int R){
	while(L<R){
		int mid=(L+R)>>1;
		if(x[mid]-x[y-1]>d){
			R=mid;
		}
		else L=mid+1;
	}
	return R;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n<=9){
		long long int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					continue;
				}
				if(check(i,j)){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	else{
		long long int ans=0;
		for(int i=1;i+3<=n;i++){
			int p=fid_up(i,i,n);
			if(p-i<2){
				continue;
			}
			int p2=fid_up(p-1,p-1,n);
			if(p2<=p){
				continue;
			}
			int p3=fid_down(p-1,p+1,p2);
			ans+=(p2-p3+1);
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}