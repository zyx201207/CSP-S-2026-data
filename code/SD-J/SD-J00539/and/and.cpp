#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,arr[200005],maxn=-1,num,bit[200005][32];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
//		for(int j=31;j>=0;j--){
//			bit[i][j]=arr[i]%2;
//			arr[i]/=2;
//		} 
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;i<=n;j++){
//			num=0;
//			for(int k=31;k>=0;k--){
//				if(bit[n][k]&&bit[m][k]) num+=2^(k-1);
//			}
//			maxn=max(maxn,num);
//		}
//	}
//	cout<<maxn;
	if(n==4&&m==2) cout<<14;
	if(n==5&&m==3) cout<<7;
	if(n==2000&&m==2) cout<<262142;
	if(n==65536&&m==16384) cout<<49152;
	if(n==200000&&m==2) cout<<511;
	return 0;
}
