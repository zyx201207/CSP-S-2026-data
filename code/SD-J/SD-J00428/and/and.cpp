#include<iostream>
#include<cstdio>
#define int long long
//#define const 998244353
using namespace std;
int n,m,a[200010],ans;bool isfail[200010]; 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		int k=0;
		for(int j=1;j<=n;j++){
//			cout<<"isfail["<<j<<"]="<<isfail[j]<<"\n";
			if(!isfail[j]&&(a[j]&(1<<i))){
				k++;
//				cout<<"!fail "<<"num["<<j<<"]="<<a[j]<<"&"<<(1<<i)<<"\n";
			}
		}
//		cout<<"for "<<i<<" is "<<k<<"\n";
		if(k>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if((a[j]&(1<<i))==0)isfail[j]=1;
//				cout<<"a[j]&(1<<i)=="<<(a[j]&(1<<i))<<"\n";
			}
		}
	}
	cout<<ans;
	return 0;
}
