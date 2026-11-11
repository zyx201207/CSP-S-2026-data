#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N=2e6+5,INF=0x3f3f3f3f3f3f3f3f;
int c,T,n,d,a[N],ans,cnt,res=0,distance;
void dfs(int now,int intention,int sum){
	if(now==intention){
		if(sum==ans) cnt++;
		if(sum<ans){
			ans=sum;
			cnt=1;
		}
		return;
	}
	for(int i=intention;i>now;i--){
		if(a[i]-a[now]>d) continue;
		dfs(i,intention,sum+1);
	}
}
void subtask_300(){
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		res=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=INF;
				cnt=0;
				dfs(i,j,0);
				if(cnt==2) res++;
			}
		}
		cout<<res<<endl;
	}
	exit(0);
}
//void dfsA(int now,int intention,int sum,int l){
//	if(now==intention){
//		if(l==distance) 
//		return;
//	}
//	for(int i=intention;i>now;i--){
//		if(a[i]-a[now]>d) continue;
//		dfs(i,intention,sum+1,min(l,a[i]-a[now]));
//		break;
//	}
//}void subtask_A(){
//	while(T--){
//		cin>>n>>d;
//		for(int i=1;i<=n;i++){
//			cin>>a[i];
//			if(i>1) distance=a[i]-a[i-1];
//		}
//		for(int i=d+1;i<distance*d;i++){
//			
//		}
//	}
//	exit(0);
//}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c<=20) subtask_300();
//	if(c>=11 && c<=12) subtask_A(); 
//	if(c==13 || c==14) subtask_B();
	return 0;
} 
