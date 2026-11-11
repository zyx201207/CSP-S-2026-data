#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define first fi
#define second se
const int N=2e6+10;
const int mod=998244353;
int c,T,n,d,a[N],cnt;
bool ck(int s,int x,int y,int t){
	return ((x-s)<=d&&(y-s)<=d&&(t-x)<=d&&(t-y)<=d&&(t-s)>d);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i+3<=n;i++){
			int r=i+4;
			if(ck(a[i],a[i+1],a[i+2],a[i+3])){
				cnt++;
				while(a[r]-a[i+1]<=d&&r<=n)cnt++,r++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
} 