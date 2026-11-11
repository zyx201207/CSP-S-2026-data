#include<bits/stdc++.h>
using namespace std;
int n,a;
string s;
char b;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>b;
		while(a--){
			s+=b;
		}
	}
	int l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]==s[r]){
			l++;
			r--; 
		}
		else{
			cnt++;
			l++;
			r--;
		}
	}
	cout<<cnt;
	return 0;
}
