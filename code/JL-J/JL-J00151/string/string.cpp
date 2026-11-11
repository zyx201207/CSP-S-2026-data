#include<bits/stdc++.h>
#define int long long
using namespace std;
int ansa=0,ansb=0;
int l=0;
string s="";
int n;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        char c;
        cin>>c;
        l+=a;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-1-i]){
            ansa++;
        }
    }
    for(int i=0;i<l/2;i++){
        if(s[l-1-i]!=s[i]){
            ansb++;
        }
    }
    cout<<min(ansa,ansb);

    return 0;
}
