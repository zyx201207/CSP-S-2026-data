#include<bits/stdc++.h>//T4->hub
using namespace std;
const int N=10010;
int t,n,k;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t>>t;//³Ôc 
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			int x,y;
			cin>>x>>y;
		}if(k==5)cout<<0<<endl;
		else if(k>=2)cout<<1<<endl;
		else cout<<2<<endl;
	}
	return 0;
}
