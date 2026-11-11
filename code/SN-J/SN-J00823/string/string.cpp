//高梓焱SN-J00823西安市第三中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,c,ans=0,l=0;
	char b;
	string a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c>>b;
		for(int j=0;j<c;j++){
			a+=b;
		}
		l+=c;
	}
	for(int i=0;i<=int(l/2);i++){
		if(a[i]!=a[l-1-i]){
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}
