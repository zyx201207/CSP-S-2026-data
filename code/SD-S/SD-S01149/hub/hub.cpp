#include<bits/stdc++.h>
using namespace std;



int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k
		int maxl=1,maxr=0;
		for(int i=1;i<=n;i++){
			int l,r;
			cin>>l>>r;
			if(maxr==l&&r==l+1){
				maxr=r;
			}
		}
		cout<<(maxr-maxl+1)/4<<"\n"
	}

	return 0;
} 
