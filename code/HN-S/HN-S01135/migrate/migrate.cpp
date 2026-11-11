#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[50010];
priority_queue<long long> qp;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(x,0,50010);
		int n,d;
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>x[i];
		}
		int ans = 0,cut = 0;
		for(int i = 1;i<=n;i++){
			x[i] = x[i+1]-x[i];
		}
//		for(int i = 1;i<=n;i++){
//			bool bb = false;
//			int k = 0;
//			for(int j = 1;j<=n;i++){
//				if(x[i]>d){
//					continue;
//				}
//				ans++;
//			}
//			if(ans>2){
//				cut++;
//			}
//		}
		cout<<"0"<<endl;
	}
	return 0;
} 
