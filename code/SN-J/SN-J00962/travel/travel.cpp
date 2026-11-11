#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d,s,t,n,j,m,k,xc,o,p;
	cin>>a>>b>>c>>d>>s>>t>>n>>j>>m>>k>>xc>>o>>p;
	if(a==j&&b==m){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(d==xc&&s==o){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(t=="A"&&p=="B"){
		cout<<1;
	}else if(t=="C"&&p=="B"){
		cout<<1;
	}else if(t=="C"&&p=="A"){
		cout<<1;
	}else if(t=="D"&&p=="E"){
		cout<<1<<1;
		return 0;
	}else if(t=="B"&&p=="A"){
		cout<<1;
	}else if(t=="B"&&p=="C"){
		cout<<1;
	}else if(t=="A"&&p=="C"){
		cout<<1;
	}else if(t=="E"&&p=="D"){
		cout<<1<<1;
		return 0;
	}else{
		cout<<0;
	}
	if(t=="A"&&p=="B"){
		cout<<1;
	}else if(t=="C"&&p=="B"){
		cout<<1;
	}else if(t=="C"&&p=="D"){
		cout<<1;
	}else if(t=="D"&&p=="E"){
		cout<<1;
		return 0;
	}
	if(t=="B"&&p=="A"){
		cout<<1;
	}else if(t=="B"&&p=="C"){
		cout<<1;
	}else if(t=="D"&&p=="C"){
		cout<<1;
	}else if(t=="E"&&p=="D"){
		cout<<1;
		return 0;
	}else{
		cout<<0;
	}
	return 0;
}

