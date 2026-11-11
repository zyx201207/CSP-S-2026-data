#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
string s;
long long sum;
bool f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i]>>c[i];
	}
	for(int i=2;i<=n;i++){
		if(c[i]!=c[i-1]){
			break;
		}
		if(i==n){
			cout <<"0";
			return 0;
		}
	}
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			break;
		}
		if(i==n){
			f=1;
		}
	}
	if(f==1){
		for(int i=1;i<=n/2;i++){
			if(c[i]!=c[n-i+1]){
				sum+=a[i];
			}
		}
		cout <<sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(long long i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			sum++;
		}
	}
	cout <<sum;
	return 0;
}
