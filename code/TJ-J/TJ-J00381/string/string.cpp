#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,f=0,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s[f]=c[i];
			f++;
		}
	}
	for(int i=0;i<f/2;i++){
		if(s[i]!=s[f-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
