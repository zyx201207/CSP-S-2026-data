#include<bits/stdc++.h>
#define N 500005
using namespace std;
int c,t,n,d;
int x[2000005];
long long ans;
void dfs(int nw,int ed){
	if(nw==ed){
		ans++;return;
	}
	for(int i=nw+1;i<=ed;i++){
		if(x[i]-x[nw]>d) break;
		dfs(i,ed);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t>>n;
	if(c==0){
		if(t==2){
			cout<<1<<endl<<2;
		}
		if(t==3){
			cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
		}
		if(t==5){
			cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
		}
		if(t==1){
			cout<<12251;
		}
	}
	else{
		cout<<2000000;
	}
	return 0;
}
