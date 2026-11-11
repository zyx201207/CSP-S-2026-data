#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5002;
ll a[N];
void solve(){
	int n,d;
	cin>>n>>d;
	if(n<=3){cout<<0<<'\n';return;}
	for(int i=1;i<=n;i++)cin>>a[i];
	int num=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d)continue;
//			bool ok=1;
//			int cnt=0;
//			for(int k=i+1;k<j;k++){
//				if(a[k]-a[i]>d || a[j]-a[k]>d){ok=0;break;}
//				cnt++;
//			}
			if(a[j]-a[i]<=2*d && j-i==3)num++;
			else break;
//			if(ok==1 && cnt==2)num++;
//			else break;
		}
	}
	cout<<num<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
