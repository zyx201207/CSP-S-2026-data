#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200009];
char c[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int cnt=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

