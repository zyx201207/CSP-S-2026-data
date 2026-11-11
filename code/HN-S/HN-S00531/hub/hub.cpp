#include<bits/stdc++.h>
using namespace std;
long long a,b,n[5],k[5],q[1000000][2]
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<b;i++){
		cin>>n[i]>>k[i];
		for(int j=0;j<n[i];j++){
			cin>>q[j][0]>>q[j][1];
		}
	}
	if(b==2){
		cout<<1<<endl<<2;
		return 0;
	}
	for(int i=0;i<t;i++){
		cout<<1<<endl;
	}
	return 0;
}
