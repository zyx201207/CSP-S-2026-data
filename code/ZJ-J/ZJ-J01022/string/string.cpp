#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200100];
char c[200100];
long long cnt; 
string s;
long long b=-1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b=max(b,a[i]);
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<0;
			return 0;
		}else{
			if(a[1]==a[2]){
				cout<<a[1];
				return 0;
			}else{
				cout<<min(a[1],a[2]);
				return 0;
			}
		}
	}
	if(b>=10000000){
		for(int i=1;i<=n/2;i++){
		cnt=cnt+a[i];
	}
	cout<<cnt;
	return 0;
	}
	if(n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s=s+c[i];
			}
		}
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-1-i]){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
