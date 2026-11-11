#include<bits/stdc++.h>
using namespace std;
long long n; 
long long a[200005];
string s;
int cmp(int x,int y){
	return x>y;
}
string w;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		for(int j=0;j<x;j++){
			s+=c;
		}
		
		for(int j=s.size()-1;j>=0;j--){
			w+=s[i];
		}
		
		a[c-'a']+=x;
	}
	if(s==w){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[1];
	return 0;
} 
