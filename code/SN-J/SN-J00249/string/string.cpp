#include<bits/stdc++.h>
using namespace std;
string s,l;
int n;
const int N=2e5+5;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=a[i];j++){
			l+=c[i];
		}
	}
	if(l==s){
		cout<<0;
		return 0;
	}
	int sum=0;
	for(int i=0;i<=n/2;i++){
		if(s[i]!=l[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
