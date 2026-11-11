#include<bits/stdc++.h>
using namespace std;
#define LL long long
string s="",s1="";
LL ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i =0;i <n;i++){
		int sl;
		char x;
		cin >> sl >> x;
		for(int j = 0;j < sl;j++){
			s+=x;
		}
	}
	s1=s;
	LL mid= s.size()/2;
	reverse(s1.begin(),s1.end());
	for(int i =mid;i<s.size();i++){
		if(s1[i] != s[i]){
			ans ++ ;
		}
		
	}
	cout << ans;
	return 0;
	
	
	
	
}