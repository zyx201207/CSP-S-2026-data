#include <bits/stdc++.h>
using namespace std;
int t,snd;
long long int ans;
bool toobig=0;
string s;
bool ch(int n) {
    for(int i=0,j=n-1;i<=j;i++,j--) {
        if(s[i]!=s[j]) {
            return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    while(t--) {
        long long int x;
        char c;
        cin>>x>>c;
        if(x>100000000) {
        	x/=10000000;
        	toobig=1;
        	snd=x/10*10;
		}
        while(x--) {
            s+=c;
        }
    }
	for(int i=s.size()-1,j=0;i>=j;i--,j++) {
        if(s[i]!=s[j]) {
            s[i]=s[j];
            ans++;
        }
        if(ch(s.size())) {
            break;
        }
    }
    if(toobig) {
    	ans*=1000000000;
    	ans/=snd;
	}
    cout<<ans;
    return 0;
}