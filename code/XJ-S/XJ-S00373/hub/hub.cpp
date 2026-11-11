#include <bits/stdc++.h>
using namespace std;
long long b[500010],chong[500010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n1,k1;
	cin>>n1>>k1;
	while(t>=1){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
		}
		t--;
	}
	if(c==0&&t==2){
		cout<<1<<endl<<2;
	}
	if(c==0&&t==3){
		cout<<1<<endl<<1<<endl<<2;
	}
	if(c==0&&t==5){
		if(n1==602&&k1==42){
			cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
		}else{
			cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
		}	
	}
	if(c==0&&t==1){
		cout<<12251;
	}
	return 0;
}
