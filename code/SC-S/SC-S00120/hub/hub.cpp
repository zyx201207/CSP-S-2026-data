#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>t;
	while(t){
		t--;
		cin>>n>>m;
		int l[1000006],r[1000006],x=1e9;
		for(int i=1;i<n;i++){
			cin>>l[i]>>r[i];
			x=min(l[i],min(r[i],x));
		}
		cout<<x;
	}
	return 0;
}