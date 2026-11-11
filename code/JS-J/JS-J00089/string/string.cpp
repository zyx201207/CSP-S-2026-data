#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s1,s2;
    int cnt=0;
    while(n--){
        int l;
        string ch;
        cin>>l>>ch;
        for(int i=1;i<=l/2;i++){
            s1=s1+ch;
            s2=ch+s2;
        }
        cnt+=l;
    }
    int ans=0;
    for(int i=0;i<cnt/2;i++){
        if(s1[i]!=s2[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
