#include<bits/stdc++.h>
#define int long long
using namespace std;
string s,s2,s3;
int num,ans;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        num+=t;
        string s1;
        cin>>s1;
        for(int i=1;i<=t;i++){
            s+=s1;
        }
    }
    for(int i=0;i*2<num;i++){
        s2+=s[i];
    }
    for(int i=num-1;i>=num/2;i--){
        s3+=s[i];
    }
    cout<<s2<<' '<<s3<<' ';
    for(int i=0;i<num/2;i++){
        if(s2[i]!=s3[i]){
            ans+=1;
        }
    }
    cout<<ans;
    return 0;
}
