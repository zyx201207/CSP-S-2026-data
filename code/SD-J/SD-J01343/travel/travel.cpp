#include<bits/stdc++.h> 
using namespace std;
int toint(char c){
	if(c!='D') return c-'A'+1;
	else return 5;
}
bool isl(string a,string b){
	char ca=a[a.size()-1],cb=b[b.size()-1];
	int s[10];
	memset(s,0,sizeof s);
	s[toint(ca)]++;
	s[toint(cb)]++;
	for(int i=1;i<=5;i++) s[i]+=s[i-1];
	if(s[3]==2 || s[5]-s[3]==2) return 1;
	else return 0;
}
bool checker(string a,string b,string c,string d){
	if(a!=c) return 0;
	if(b.substr(0,b.size()-1)==d.substr(0,d.size()-1)){
		if(abs(toint(b[b.size()-1])-toint(d[d.size()-1]))==1 && isl(b,d)){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	string a,b,c,d;cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else cout<<0;
	if(a==c && b.substr(0,b.size()-1)==d.substr(0,d.size()-1)) cout<<1;
	else cout<<0;
	if(a==c && b.substr(0,b.size()-1)==d.substr(0,d.size()-1) && isl(b,d)) cout<<1;
	else cout<<0;
	if(checker(a,b,c,d)) cout<<1;
	else cout<<0;
	return 0;
}
