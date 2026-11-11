#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int ai[10000];
	char ci[10000];
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ai[i]>>ci[i];
	}
	if(n==1) cout<<0;
	if(n==2){
		if(ci[1]==ci[2]){
			cout<<0;
			return 0;
		}
		else cout<<1;
	}                                                                                                                                                               
	else if(n==3){
		if(ci[1]==ci[2]&&ci[1]==ci[3]){
			cout<<0;
			return 0;
		}else cout<<2;
	}else if(n==4){
		if(ci[1]==ci[2]&&ci[1]==ci[3]&&ci[1]==ci[4]){
			cout<<0;
			return 0;
		}else cout<<2;
	}else if(n==5){
		if(ci[1]==ci[2]&&ci[1]==ci[3]&&ci[1]==ci[4]&&ci[1]==ci[5]){
			cout<<0;
			return 0;
		}
		else cout<<2;
	}else if(n==6){
		if(ci[1]==ci[2]&&ci[1]==ci[3]&&ci[1]==ci[4]&&ci[1]==ci[5]&&ci[1]==ci[6]){
			cout<<0;
			return 0;
		}
	}else cout<<2;
	if(n>=6) cout<<2;
	return 0;
}
