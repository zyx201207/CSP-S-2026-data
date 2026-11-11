#include<bits/stdc++.h>
using namespace std;
#define int long long
string ss;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,al=0,ans=0;
    cin>>n;
    for(int a=0;a<n;a++){//n
        int q;
        char w;
        cin>>q>>w;
        for(int s=0;s<q;s++){
            ss.push_back(w);
        }
        al+=q;
    }
    for(int a=0,s=al-1;a<s;a++,s--){
        if(ss[a]!=ss[s]){
            ans++;
        }
    }
    cout<<ans;
}
