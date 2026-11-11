#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt,ans;
string s;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        while(a--) s+=c;
    }
    for(int i=floor(s.size()/2)-1;i>=0;i--){
        if(s[i]!=s[s.size()-1-i]) cnt++;
    }
    ans=cnt;
    cnt=0;
    for(int i=ceil(s.size()/2);i<=s.size()-1;i++){
        if(s[i]!=s[s.size()-1-i]) cnt++;
    }
    cout<<min(ans,cnt);
    return 0;
}
