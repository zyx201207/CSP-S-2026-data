#include<bits/stdc++.h>
using namespace std;
long long n,a,l=1,r=0,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c;
	vector<char> s;
	s.push_back(' ');
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--){
			s.push_back(c);
			++r;
		}
	}
	while(l<r){
		if(s[l]!=s[r]) cnt++;
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}

