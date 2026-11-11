#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;cin>>n;
	string s;
    for(int i=1;i<=n;++i){
    	int a;
		char b;cin>>a>>b;
    	for(int i=1;i<=a;++i)s+=b;
	}
	vector<char>ch(s.size());
	int sum=1;
	for(char c:s){
	    ch[sum]=c;	
	    sum++;
	}
	int l,r;
	if(s.size()%2==0)l=s.size()/2,r=l+1;
	else l=s.size()/2,r=l+2;
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(ch[l]!=ch[r])cnt++;
		l--,r++;
	}
	cout<<cnt;
	return 0;
	}