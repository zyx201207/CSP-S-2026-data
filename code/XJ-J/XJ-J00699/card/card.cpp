#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e5+10;
long long int n,m;
int a[N],b[N],t[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=m;i++){
//		cout<<0<<" ";
//	}
	for(int i=1;i<=n;i++){
		int vis=1,cnt=1;
		for(int j=i;j<=n;j++){
			b[vis]=a[j];
			vis++;
			cnt++;
			for(int k=1;k<=vis-1;k++){
				if(b[j]==b[k]){
					vis-=cnt;
					cnt=0;
					break;
				}
			}			
			vis++;
		}
//		for(int j=1;j<=vis;j++){
//			cout<<b[i]<<" ";
//		}
//		cout<<'\n';
		for(int i=1;i<=m;i++){
			for(int j=1;j<=vis;j++){
				if(b[j]==i){
					t[i]++;
				}
			}
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]-i+1<<" ";
	}
	return 0;
}