#include<bits/stdc++.h>
using namespace std;
#define FILENAME "string"
size_t n,ans;
string s;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen(FILENAME ".in","r",stdin);
	freopen(FILENAME ".out","w",stdout);

	cin>>n;
	for(size_t i=1;i<=n;i++){
		char c;
		size_t a;
		cin>>a>>c;
		s+=string(a,c);
	}
	size_t m;
	if(s.size()%2==0){
		m=s.size()/2-1;
		s.insert(s.begin()+m,'#');
		m++;
	} else m=s.size()/2;
	for(size_t i=1,r=s.size()-m;i<r;i++){
		if(s[m+i]!=s[m-i]) ans++;
	}

	cout<<ans;

	return 0;
}