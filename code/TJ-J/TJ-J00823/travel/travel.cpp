#include <bits/stdc++.h>
using namespace std;
int main(){
	int l,a,end=0,ll=0;
	cin>>l;
	char q[l+1],s[l+1];
	char ss[1000000];
	ll=0;
	for(int i=1;i<=l;i++){
		cin>>s[i]>>q[i];
		for(int j=1;j<=s[i];j++){
			ss[j+ll]==q[i];
		}
		ll+=s[i];
		cout<<s[i]<<'ll';
	}
	for(int j=1;j<=ll;j++){
		cout<<ss[j];
	}	
	if(ll%2==0){
		
	}else{
	}
}
