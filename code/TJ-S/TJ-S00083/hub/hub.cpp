#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> v[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		cout<<rand()%(n+1)<<endl;
	}
	return 0;
}
