#include<bits/stdc++.h>
using namespace std;
const int n=1e6;
int main(){
	freopen("hub6.in","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T=2;
	cout<<"0 "<<T<<"\n";
	while(T--){
		int k=2;
		cout<<n<<" "<<k<<"\n";
		for(int i=1;i<n;i++) cout<<i<<" "<<i+1<<"\n";
	}
	return 0;
}