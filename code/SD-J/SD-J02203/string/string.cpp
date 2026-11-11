#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a;
		cin>>c;
		for(int j=1; j<=a; j++){
			s+=c;
		}
	}
	int l=0,r=s.size()-1;
	while(l!=r){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
