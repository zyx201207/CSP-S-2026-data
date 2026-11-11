#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int> v[500000];
int main(){
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		cout<<n<<"\n";
	}
	return 0;
}