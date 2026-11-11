#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
string s;
int n,a[N],c,l;
long long int f;
int kk(int x){
	for(int i=1,j=x;i<x/2,j>x/2;i++,j--){
		if(s[i]!=s[j]){
			f+=min(a[i],a[j]);
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	c=100000000;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s[i];	
		l+=a[i];	
	}
	for(int i=1;i<=n;i++){
		if(s[i]==s[i-1]){
			c++;
		}
	}
	if(c==n){
		cout<<0;
		return 0;
	}
	c=0;
	kk(n);
	cout<<f;
	/*if(l%2==0){
		for(int i=0;i<n;i++){
			c+=a[i];
			if(c<=l&&s[i]!=s[i+l%2]){
				f++;
			}
		}
	}else{
		for(int i=0;i<n;i++){
			c+=a[i];
			if(c<=l&&s[i]!=s[i+l%2]){
				f++;
			}
		}
	}
	cout<<f;*/
	return 0;
}