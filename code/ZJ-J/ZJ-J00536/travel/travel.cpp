#include<bits/stdc++.h>
using namespace std;
int ans,a,b,aa,bb;
char a_,b_;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>a_>>b>>bb>>b_;
	ans=1;
	if(a!=b)ans=0;
	cout<<ans;
	if(ans==0){
		cout<<"000";
		return 0;
	}
	ans=1;
	if(aa!=bb)ans=0;
	cout<<ans;
	if(ans==0){
		cout<<"00";
		return 0;
	}
	ans=0;
	if(a_<='C'&&b_<='C') ans=1;
	else if(a_>='D'&&b_>='D') ans=1;
	cout<<ans;
	if(ans==0) cout<<0;
	else{
		if(abs(a_-b_)==1) cout<<1;
		else cout<<0;
	}
}
