#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+7;
int a[MAXN];
int N,M,ans;
void Find(int id){
	int tmp=0,cnt=0;
	int val=a[id];
	for(int i=id;i>=1;i--){
		if(a[i]<=val){
			cnt+=val-a[i];
			tmp++;
		}
		if(cnt>M){
			ans=max(ans,tmp-1);
			return ;
		}
	}
	ans=max(ans,tmp);
	return ;
}
void solve(){
	cin>>N>>M;
	for(int i=1;i<=N;i++)cin>>a[i];
	sort(a+1,a+1+N);
	for(int i=N;i>=1&&(((double)clock()/CLOCKS_PER_SEC)<0.93);i--){
		Find(i);
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN=5e5+7;
//const int INF=1e18;
//int N,M,mx=-INF,mi=INF;
//int a[MAXN],ans=0;
//bool check(int x){
////	cout<<"__"<<x<<'\n';
//	int cost=0,tmp=0;
//	for(int i=N;i>=1;i--){
//		if(a[i]>x)continue;
//		else{
////			cout<<a[i]<<'\n';
//			cost+=(x-a[i]);
////			cout<<"_______"<<cost<<'\n';
//			tmp++;
//		}
//		if(cost>M){
//			ans=max(ans,tmp-1);
////			cout<<1111<<'\n';
//			return false;
//		}
//	}
//	ans=max(ans,tmp);
//	return true;
//}
//void Mid(int L,int R){
//	while(L<R){
//		if(R-L==1){
//			check(L);
//			check(R);
//			return ;
//		}
//		int mid=(L+R)>>1;
////		if(L==3)return ;
//		if(check(mid))L=mid;
//		else 		  R=mid-1;
////		cout<<L<<' '<<mid<<" "<<R<<'\n';
//	}
//}
//void solve(){
//	cin>>N>>M;
//	for(int i=1;i<=N;i++)cin>>a[i];
//	sort(a+1,a+1+N);
//	for(int i=1;i<=N;i++)mx=max(mx,a[i]),mi=min(mi,a[i]);
//	Mid(mi,mx);
////	check(10);
//	cout<<ans;
//}
//signed main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
//	solve();
//	return 0;
//}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 2
-3 -1 9 9 10
*/