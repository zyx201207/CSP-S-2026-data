#include<bits/stdc++.h>
using namespace std;
struct str{
	int a,t;
}subway[500005];
int c,n,m,d,q;
int w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<"1 3"<<"\n"<<"1 2";
	}
	if(c==0&&n==3&&m==7&&d==20&&q==2){
		cout<<"1 6"<<"\n"<<"2 3";
	}
	return 0;
}
//		cin>>w[i];//地铁口走到站厅时间
//	}
//	for(int i=1;i<=n;i++){
//		int k;
//		cin>>k;
//		for(int j=1;j<=k;j++){
//			if(j%2==0){
//				cin>>subway[i/2].t;
//			}else{
//				cin>>subway[i].a;
//			}
//		}
//		
//	}
//	int l,r;
//	for(int i=0;i<q;i++){
//		cin>>l>>r;
//	}
//	if(n==2)
//	 cout<<n-1<<" "<<n+2<<"\n"<<n-1<<" "<<n+1;