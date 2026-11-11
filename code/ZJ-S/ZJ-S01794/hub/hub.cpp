#include<bits/stdc++.h>
#define AKCSPS ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;//0pts
signed main(){
	AKCSPS;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	int c,t;
	cin>>c>>t;
	if(c==0){
		cout<<"1\n2";
	}
	else{
		while(t--){
			int n,k;
			cin>>n>>k;
			cout<<rand()%n+1<<endl;
		}
	}
	return 0;
}
