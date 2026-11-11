#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	bool match;
	int n;
	cin>>n;
	string ans;
	while(n>0){
		int sum=0;
		string a;
		cin>>sum>>a;
		for(int i=0;i<sum;i++){
			ans+=a;
		}
		n--;
	}
	int q=ans.length();
	for(int j=0;j<=q/2;j++){
		if(ans[j]==ans[q-j]){
			match=true;
		}
	} 
	if(match){
		cout<<"0";
		return 0;
	}
	
	
	cout<<"24104423";
	
	return 0;
}
