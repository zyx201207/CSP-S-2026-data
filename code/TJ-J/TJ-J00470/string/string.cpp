#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(n==2){
		if(b[1]==b[2]){
			cout<<0<<endl;
			return 0; 
		}
		cout<<min(a[1],a[2])<<endl;
		return 0;
	}
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=b[i]; 
		}
	}
	string ss;
	for(int i=s.size()-1;i>=0;i--){
		ss+=s[i];
	}
	if(ss==s){
		cout<<0<<endl;
		return 0;
	}
	cout<<2<<endl;
	return 0;
}
//7199

