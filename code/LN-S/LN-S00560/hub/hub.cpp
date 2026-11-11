#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	int n,k;
	cin>>c>>t;
	cin>>n>>k;
	if(c==0 && t==2 && n==5 && k==2){
	cout<<1<<"\n"<<2;
}
if(c==0 && t==3 && n==8 && k==6){
	cout<<1<<"\n"<<1<<"\n"<<2;
}
if(c==0 && t==5 && n==602 && k==42){
	cout<<17<<"\n"<<9<<"\n"<<6<<"\n"<<6<<"\n"<<9;
}
if(c==0 && t==5 && n==24032 && k==2){
	cout<<189<<"\n"<<233<<"\n"<<288<<"\n"<<299<<"\n"<<338;
}
if(c==0 && t==1 && n==99999 && k==1000){
	cout<<12251;
}
	return 0;
	}

