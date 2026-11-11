
#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int x;
		string s1;
		cin>>x>>s1;
		for(int i=1;i<=x;i++){
			s+=s1;
		}
	}
	int l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]){
			cnt++;
			l++;
			r--;
		}else{
			l++;
			r--;
		}
	}
	cout<<cnt;
	return 0;
}
