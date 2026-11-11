#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        while(x--){
            s+=y;
        }
    }
    int len=s.size();
    int ans=0;
    for(int i=0;i<=len/2;i++){
        if(s[i]!=s[len-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
