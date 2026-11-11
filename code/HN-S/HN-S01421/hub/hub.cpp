#include<bits/stdc++.h>
using namespace std;
vector<int>v[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(k==n)cout<<"0\n";
		else{
			// cout<<2<<"\n";
			int yu=((n+1)/2);
			if(k==1)cout<<max((yu+1)/2,1)<<"\n";
			else if(k==2)cout<<max((yu+1+3)/4,1)<<"\n";
			else cout<<max((yu+4-(k-2))/4,1)<<"\n";
		}
	}
	return 0;
}