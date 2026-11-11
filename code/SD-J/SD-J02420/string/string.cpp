#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n=0;
	long long ans=0;
	cin>>n;
	while(n--){
		long long l;
		char c;
		cin>>l>>c;
		while(l--){
			s+=c;
		}
	}
	long long x=-1,y=s.size();
	for(int i=0;i<s.size()/2;i++){
		x++;y--;
		if(s[x]!=s[y]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

