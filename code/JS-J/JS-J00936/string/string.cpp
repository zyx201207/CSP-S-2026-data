#include <bits/stdc++.h>
using namespace std;
long long n,c,t=0,ans=0;char a;
vector<char>s;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s.push_back(' ');
	for(int i=1;i<=n;i++){
        cin>>c>>a;
        for(int j=1;j<=c;j++){
            s.push_back(a);
            t++;
        }
	}
	for(int i=1;i<=t;i++){
        if(i>=t-i+1){
            break;
        }
        if(s[i]!=s[t-i+1]){
            ans++;
        }
	}
	/*for(int i=1;i<=t;i++){
        cout<<s[i];
	}*/
	cout<<ans;
    return 0;
}
