#include<bits/stdc++.h>
using namespace std;
int n;
string s; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin >> n;
	for(int i=1;i<=n;i++){
		int a;
		char ls;
		cin >> a;
		cin >> ls;
		for(int i=1;i<=a;i++){
			s+=ls;
		} 
	}

	int len=s.size();
	int l=0,r=len-1;
	int ans=0;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;r--;
	}
	cout << ans;
	
	
	return 0;
} 
