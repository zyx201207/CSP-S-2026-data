#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long a;char b;
        cin>>a>>b;
        for(int j=1;j<=a;j++){
            s=s+b;
        }
    }
    int ans=0;
    int md=s.size()/2;
    if(s.size()%2==0){
        for(int i=md;i<s.size();i++){
            if(s[i]!=s[md*2-i-1]){
                ans++;
            }
        }
    }else if(s.size()%2==1){
        md++;
        for(int i=md;i<s.size();i++){
            if(s[i]!=s[md*2-i-2]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
