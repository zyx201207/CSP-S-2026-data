#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	string s,n,m,a;
	cin>>s>>n>>m>>a;
	if(s==m){
		cout<<1<<" ";
	}else{
		cout<<0<<" ";
		cout<<0<<" ";
		cout<<0<<" ";
		cout<<0;
		return 0;
	}
	if(n[0]==a[0]&&n[1]==a[1]){
		cout<<1<<" ";
		if((n[2]<='C'&&a[2]<='C')||(n[2]>='D'&&a[2]>='D')){
			cout<<1<<" ";
		}else{
			cout<<0<<" "<<0;
			return 0;
		}
		if((n[2]-'1'==a[2]+'0')||(n[2]+'1'==a[2]+'0')){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}else{
		cout<<0<<" "<<0<<" "<<0;
	}
	
	return 0;
}
