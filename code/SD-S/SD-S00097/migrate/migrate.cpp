#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
//	if(c<10){//BaoLi
//		for(int i=1;i<=t;i++){
//			int n,d,x[50005],cnt=0;
//			cin>>n>>d;
//			for(int j=1;j<=n;j++){
//				cin>>x[j];
//			}
//			for(int j=1;j<=n-3;j++){
//				int now=0;
//				for(int k=i+3;k<=n;k++){
////					if(check(x[j],x[k])){
//						now++;
////					}
//				}
//				if(now==2){
//					cnt++;
//				}
//			}
//			cout<<cnt<<"\n";
//		}
//	}
//	else if(c==11||c==12||c==0){//A
	for(int i=1;i<=t;i++){
		int n,d,x[50005],cnt=0,e;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		e=abs(x[2]-x[1]);
		if(d<e){
			cout<<0<<"\n";
		}
		else{
			cout<<n-3<<"\n";
		}
	}
//	}
//	else if(c==13||c==14){//B
//		for(int i=1;i<=t;i++){
//			int n,d,x[50005],cnt=0;
//			cin>>n>>d;
//			for(int j=1;j<=n;j++){
//				cin>>x[j];
//			}
//		}
//	}
//	else if(c==15||c==18){//C
//		for(int i=1;i<=t;i++){
//			int n,d,x[50005],cnt=0;
//			cin>>n>>d;
//			for(int j=1;j<=n;j++){
//				cin>>x[j];
//			}
//		}
//	}
//	else{//?
//		for(int i=1;i<=t;i++){
//			int n,d,x[50005],cnt=0;
//			cin>>n>>d;
//			for(int j=1;j<=n;j++){
//				cin>>x[j];
//			}
//		}
//	}
	return 0;
}

