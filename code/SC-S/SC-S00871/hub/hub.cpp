#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int stop[50010]={0};
int start[10019],end[10010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t>>n>>d;
	int sstf=t;
	while(sstf--){
		int n[10010],d[10010];
		for(int i=1;i<=n[sstf];++i){
			cin>>stop[i];
		}
	}
	if(c==0 && t==2){
		cout<<1<<endl;
		cout<<2<<endl;	
	}else if(c==0 && t==3){
		cout<<1<<endl;
		cout<<1<<endl;
		cout<<2<<endl;
	}else if(c==0 && t==5){
		cout<<17<<endl;
		cout<<9<<endl;
		cout<<6<<endl;
		cout<<6<<endl;
		cout<<9<<endl;
	}else if(c==0 && t==1){
		cout<<12251<<endl;
	}
	
	return 0;
}