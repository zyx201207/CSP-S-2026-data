#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	
	char c;
	long long nc;
	
	for(int i=0;i<n;i++){
		cin>>nc;
		cin>>c;
		for(int j=0;j<nc;j++){
			s+=c;
		}
	}
	
	int l=0,r=s.size()-1,cnt=0;
	while(l<r){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
