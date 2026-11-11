#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2e6+10;
#define ll long long
int c,T;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		if(n==k){
			cout<<"0\n";
			continue;
		}
		if(c==13||c==14){
			if(k>=n/2)cout<<"1\n";
			else {
				int l=2,r=n/4+1;
				while(l<r){
					int mid=l+r>>1;
					if(k>=ceil((n/2+1)*1.0/(2*mid-1)))
						r=mid;
					else l=mid+1;
				}
				cout<<l<<'\n';
			}
		}
	}
	return 0;
}
