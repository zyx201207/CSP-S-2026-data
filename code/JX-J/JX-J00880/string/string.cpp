#include<bits/stdc++.h>
using namespace std;
string s,c;
int n,a;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a>>c;
        if(a>1e5*5){
            ans+=a/2;
        }else{
            while(a--){
                s+=c;
            }
        }
    }
    int m=s.size();
    for(int i=0;i<=m/2;i++){
        if(s[i]!=s[m-i-1]) ans++;
    }cout<<ans;
    return 0;
}
