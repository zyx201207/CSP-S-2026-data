#include<bits/stdc++.h>
using namespace std;
long long n,x[200005],ans;
string s,o,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>o;
		for(int j=0;j<x[i];j++){
			s.insert(j,o);
		} 
	}
	for(int i=s.size()-1;i>=0;i--){
		s2[i]=s[i];
	}	if(n==1){
		cout<<0;
		return 0;
	}	if(n<=2){
			if(x[1]>=x[2]){
				cout<<x[2];
			}else{
				cout<<x[1];
			}
		}
	return 0;
}
