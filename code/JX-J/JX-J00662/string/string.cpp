#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int l=0,r=0,cnt=0;
    string ans;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x=0;
        string s;
        cin>>x>>s;
        for(int j=1;j<=x;j++){
            ans+=s;

        }
        s="";
    }
    r=ans.size()-1;
    while(l<=r){
        if(ans[l]==ans[r]){
            l++;
            r--;
        }else{
            cnt++;
            l++;
            r--;
        }
    }
    cout<<cnt;
    return 0;
}
