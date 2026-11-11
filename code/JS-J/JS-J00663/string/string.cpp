#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,a,cnt;
char c;
string s=" ";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>a>>c;
        while(a--) s+=c;
    }
    for(ll i=1;i<=s.size()/2;i++){
        if(s[i]!=s[s.size()-i]) cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
