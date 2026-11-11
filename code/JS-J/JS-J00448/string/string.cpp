#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt=0;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
		cin>>a>>c;
		for(int j=1;j<=a;++j){
			s+=c;
        }
    }
    for(int i=0;i<s.size();++i){
		if(s[i]!=s[s.size()-i-1]){
			s[i]=s[s.size()-i-1];
			cnt++;
	    }
	}
	cout<<cnt;
	return 0;
}
