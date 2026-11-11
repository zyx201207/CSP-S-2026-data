#include<bits/stdc++.h>
using namespace std;
bool hui(string a){
	string b;
	for(int i=a.size();i>0;i--){
		b=a[i];
	}
	if(b==a){
		return 0;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int x;
	string s="";
	cin>>x;
	while(x--){
		int n;
		string t;
		cin>>n>>t;
		for(int i=1;i<=n;i++){
			s+=t;
		}	
	}
	if(hui(s)){
		cout<<0;
	}
	return 0;
}

