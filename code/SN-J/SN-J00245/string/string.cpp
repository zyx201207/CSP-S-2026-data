#include<bits/stdc++.h>
using namespace std;

int n,a;
char c;
vector<char> s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--){
			s.push_back(c);
		}
	}
	long long cnt=0,sz=s.size();
	for(int i=0;i*2<=s.size();i++){
		if(s[i]!=s[sz-i-1])cnt++;
	}
	cout<<cnt<<endl;

//	1145141919810
/*
	ÍêÈ«Ê¤Àû£¨Ï²
*/
	return 0;
}
