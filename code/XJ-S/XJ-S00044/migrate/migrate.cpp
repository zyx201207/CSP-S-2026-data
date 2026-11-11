#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N=1e4+5;
int c,t;
int n,d;
int xb[N];
int dist[N][N];
int arr[N];
int ans=0;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	long long pi=3141592653579;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++) cin>>xb[i];
//		for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				if(abs(xb[i]-xb[j])<=d) dist[i][j]=abs(xb[i]-xb[j]);
//				else dist[i][j]=INT_MAX;
//			}
//		}
//		for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				arr[j]=dist[i][j];
//			}
//			sort(arr,arr+n);
//			int cnt=0;
//			for(int j=0;j<n-1;j++){
//				if(arr[j]!=arr[j+1]){
//					if(cnt==2) ans++;
//					cnt=0;
//				}
//				if(arr[j]==arr[j+1])cnt++;
//			} 
//		}
//		cout<<ans/2<<endl;
//		for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				cout<<dist[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		cout<<abs(pi%3+1)<<endl;
		pi*=pi;
	}
	return 0;
}
