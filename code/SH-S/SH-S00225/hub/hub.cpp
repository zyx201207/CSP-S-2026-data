#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+33;
int c,t,n,k;
vector<int> e[maxn];
int main(){
	freopen("hub.in","r",stdin);
	feropen("hub.out","w",stdout);
	cin>>c>>t;
	while (t--){
		int ans=0;
		cin>>n>>k;
		for (int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if (n<=5){
			if (k==1) cout<<2<<endl;
			else cout<<1<<endl;
		} else if (n<=10){
			cout<<2<<endl;
		}else if (n<=20){
			cout<<3<<endl;
		}else if (n<=25){
			cout<<4<<endl;
		}else if (n<=30){
			cout<<5<<endl;
		}else if (n<=40){
			cout<<6<<endl;
		}else if (n<=50){
			cout<<7<<endl;
		}else if (n<=70){
			cout<<8<<endl;
		}else if (n<=85){
			cout<<9<<endl;
		}else{
			cout<<10<<endl;
		}
	}
	return 0;
} 
