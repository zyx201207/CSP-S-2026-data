//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//int a[500005]={};
//int b[500005]={};
//int ton[500005]={};
//int ned[500005]={};
//int were[500005]={};
//signed main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//	int n,m;
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	sort(a+1,a+n+1);
////	for(int i=1;i<=n;i++){
////		cout<<a[i]<<endl;
////	}
////	cout<<endl;
//	b[1]=1;
//	ton[1]++;
//	int maxx=1;
//	for(int i=2;i<=n;i++){
//		if(a[i-1]==a[i]){
//			b[i]=b[i-1];
//		}else{
//			b[i]=b[i-1]+1;
//			maxx++;
//		}
////		cout<<b[i]<<endl;
//		ton[b[i]]++;
//	}
//	int need=0;
//	int nowa=a[1];
//	int where=ton[1];
//	were[1]=where;
//	int k=1;
//	int ansmax=ton[1];
//	int begun=1;
//	for(int i=2;i<=maxx;i++){
//		cout<<ton[i]<<endl;
//		need+=(where-begun+1)*(a[where+1]-a[where]);
//		ned[i]=need;
//		cout<<where<<" "; 
//		where+=ton[i];
//		were[i]=where;
//		nowa=a[where];
//		cout<<"where="<<where<<",a="<<nowa<<",need="<<need<<",ton="<<ton[i]<<endl;
//		if(need>m){
//			for(int j=begun;j<=where;j++){
//				need-=nowa-a[j];
//				begun++;
//				if(need<=m){
//					ansmax=where-begun+1;
//					break;
//				}
//			}
//		}else{
//			ansmax=where-begun+1;
//		}
//	}
//	cout<<ansmax;
//	return 0;
//} 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005]={};
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	int need=0;
	int ans=0;
	int begun=1;
	for(int i=2;i<=n;i++){
		need+=(i-begun)*(a[i]-a[i-1]);
//		cout<<"where="<<i<<",need="<<need<<endl;
		if(need>m){
			for(int j=begun;j<=i;j++){
				need-=a[i]-a[j];
				begun++;
				if(need<=m){
					break;
				}
			}
		}
//		cout<<begun<<" "<<i<<endl;
		ans=max(ans,i-begun+1);
	}
	cout<<ans;
	return 0;
} 
