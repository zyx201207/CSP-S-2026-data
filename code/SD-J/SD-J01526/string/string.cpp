#include<bits/stdc++.h>
using namespace std;

string s="1";
int n,a[1000086],c,l;
char b[1000086];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
		l+=a[i];
	}
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l+1-i]){
			c++;
		}
	}
	cout<<c;
	return 0;
}
