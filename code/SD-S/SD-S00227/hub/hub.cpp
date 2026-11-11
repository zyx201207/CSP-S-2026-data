#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int c,T;
int n,k;
vector<int> v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
		}
		int m=n/2;
		k--;
		if(k<m+1){
			cout<<m+1-k<<"\n"; 
		}
		else{
			cout<<1<<"\n";
		}
	}
}
