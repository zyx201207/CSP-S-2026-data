#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int n;
	cin>>n;
	string s=" ";
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	long long r=s.size(),h=0;
	for(int i=1;i<=s.size()/2;i++){
		if(s[i]!=s[r]){
			h++;
			
		}
		r--;
	}
	cout<<h;
	return 0;
}
