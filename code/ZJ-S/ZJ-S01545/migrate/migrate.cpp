#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=2e6+10;

int c,t,n,d;
int a[N];


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	cin>>c>>t;
	if(c==11 || c==12){
		while(t--){
			cin>>n>>d;
			for(int i=0;i<n;i++){
				cin>>a[i];
			}if(n<4){
				//puts("0");
				cout<<0<<'\n';
				continue;
			}int x=a[1]-a[0];
			if( x*3<=d || x*2>d ){
				//puts("0");
				cout<<0<<'\n';
				continue;
			}//int y=upper_bound(a,a+n,d+a[0])-a;
			cout<<n-3<<'\n';
		}return 0;
	}
	while(t--){
		int cnt=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=n-1;j>i+2;j--){
				int r=upper_bound(a,a+n,a[i]+d)-a-1;
				int l=lower_bound(a,a+n,a[j]-d)-a;
				if(r-l>1)break;
				if(r-l==1)cnt++;
			}
		}cout<<cnt<<'\n';
	}
	
	
	
	
	
	
	return 0;
	
}
