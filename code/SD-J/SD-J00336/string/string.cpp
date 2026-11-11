#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		int m;
		cin>>m;
		string tmp;
		cin>>tmp;
		for(int i=0;i<m;i++){
			s+=tmp;
		}
	}
	int l=0,r=s.size()-1;
	int cnt=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt<<endl;
	return 0;
}
//I will AFO on CSP-2026
//goodbye my OI dream QWQ TT
//luogu id tuotuoyl(别看) 
//祝我whk加油 11:49 有点难
//别炸 
