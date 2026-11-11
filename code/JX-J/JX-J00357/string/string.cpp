#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n;
long long a[N];
char c[N];
string s;
bool cnt;
string pj(int x,char a){
	string ans;
    for(int i=1;i<=x;i++){
		ans+=a;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){
        s+=pj(a[i],c[i]);
	}
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]==s[len+1-i]) cnt=1;
		else cnt=0;
	}
	if(cnt) cout<<0;
	return 0;
}
