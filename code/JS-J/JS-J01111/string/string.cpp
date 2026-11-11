#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
string s="";
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;char c;
        cin>>x>>c;
        for(int i=1;i<=x;i++){
            s=s+c;
        }
    }
    int num=s.size();
    for(int i=0;i<=num/2;i++){
        if(s[i]!=s[num-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
