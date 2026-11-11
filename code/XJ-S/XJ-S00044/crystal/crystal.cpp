#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF=1e18;
const int N=5e5+10;
int n,m;
int ans=1;
int arr[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>arr[i];
	int s=arr[1]-arr[0];
	for(int i=0;i<n;i++){
		int sum=(arr[i]-arr[0])*(i+1)/2;
		if(sum<=m)ans=i+1;
	}
	cout<<ans<<endl;
	return 0;
}
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//const int INF=1e18;
//const int N=5e5+10;
//int n,m;
//struct crystal{
//	int id;
//	int v;
//	int cha;
//}e[N];
//int cnt[N];
//
//bool cmp1(crystal x,crystal y){
//	return x.v<y.v;
//}
//bool cmp2(crystal x,crystal y){
//	if(x.cha!=y.cha) return x.cha<y.cha;
//	return x.
//}
//
//signed main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//	cin>>n>>m;
//	for(int i=0;i<n;i++){
//		e[i].id=i;
//		cin>>e[i].v;
//		cnt[e[i].v]++;
//	}
//	sort(e,e+n,cmp1);
//	int xb=0,lock=false;
//	for(int i=0;i<n-1;i++){
//		if(e[i].v==e[i+1].v&&lock==false) xb=i,lock=true;
//		if(e[i].v!=e[i+1].v&&lock==false) e[i].cha=e[i+1].v-e[i].v;
//		if(e[i].v!=e[i+1].v&&lock==true){
//			int cha=e[i+1].v-e[i].v;
//			for(xb;xb<=i;xb++){
//				e[xb].cha=cha;
//			}
//		}
//	}
//	sort(e,e+n,cmp2);
//	while(m!=0){
//		
//		if(e[0].cha*cnt[e[0].v]<=m){
//			m-=e[0].cha*cnt[e[0].v];
//			cnt[e[0].v]++;
//			
//		}
//	}
//	return 0;
//}
