#include<bits/stdc++.h>
using namespace std;
#define int long long
int n2,m2,n,m;
char c,c2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	c=getchar();
	cin>>n2>>m2;
	c2=getchar();
	if(n2!=n){
		cout<<"0000";
		return 0;
	}else if(m2!=m){
		cout<<"1000";
		return 0;
	}else if((c2<'D'&&c>='D')||(c2>='D'&&c<'D')){
		cout<<"1100";
		return 0;
	}else if(c2+1==c||c+1==c2){
		cout<<"1111";
		return 0;
	}else{
		cout<<"1110";
		return 0;
	}
	return 0;
} 
