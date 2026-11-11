#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
long long n,c,t,k,u,v;
vector<int> ve[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	for(int o=1;o<=t;o++){
		cin>>n>>k;
		if(k==n){
			cout<<0<<"\n";
			continue;
		}
		if(k>=n/2+1){
			cout<<1<<"\n";
			continue;
		}
		if((n/2)%2==0){
			cout<<(n/2/2-k/2+1)/2+1<<"\n";
		}
		else{
			if(k%2==0){
				cout<<((n/2+1)/2-k/2)/2+1;
			}
			else{
				cout<<(((n/2+1)/2-(k+1)/2)+1)/2+1;
			}
		}
	}
	return 0;
}
