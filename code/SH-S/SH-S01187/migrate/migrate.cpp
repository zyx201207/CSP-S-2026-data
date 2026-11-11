#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000020
#define endl "\n"
//define iscc ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int c,t;
int idx[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//system("fc test.out test.ans\n");
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			int cnt=0;
			int n,d;
			cin>>n>>d;
			int st=1;
			for(int i=1;i<=n;i++){
				cin>>idx[i];
			}
			for(int i=1;i<=n;i++){
				if(idx[i]-idx[1]>d){
					st=i;
					break;
				}
			}
			cout<<n-st+1<<endl;
		}
	}
	return 0;
}
