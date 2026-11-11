#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long a[N];
int flag=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		long long cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			if(d<cnt*2){
				cout<<0;
				continue;
			}
			cout<<n-((d/cnt-2)*2+3);
			continue;
		}
		if(c==13||c==14){
			int si=0;
			for(int i=1;i<=n;i++){
				if(a[n]-a[i]<=d){
					si=i;
					break;
				}
			}
			for(int i=1;i<=si;i++){
				if(a[si]-a[i]<=d){
					si=i;
					break;
				}
			}
			cout<<si;
			continue;
		}
	}
	return 0;
}