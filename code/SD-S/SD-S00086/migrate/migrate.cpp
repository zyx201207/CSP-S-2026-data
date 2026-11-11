#include<bits\stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+9;
int z[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T,t;
	cin>>T>>t;
	while(t--){
//		cout<<t<<"\n";
		int n;
		ll d;
		int ans=0;
		cin>>n>>d;
		FOR(i,1,n)cin>>z[i];
		FOR(l,1,n)
		FOR(r,l+1,n){
			int lx=-1;
			int i=l,j=i,li=0;
			int cnt=1;
			while(cnt){
				while(z[j+1]-z[i]<=d){
//					cout<<j<<"--";
					if(j+1==r){
						lx=i;
						cnt=0;
						break;
					}
					j++;
				}
				if(j==li)break;
				li=i;
				i=j;
			}
			while(z[r]-z[j-1]<=d&&j>l)j--;
			if(j==lx-1){
//				cout<<l<<" "<<r<<"\n";
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
}
