#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    int ans=0;
    for(int i=0,j=s.size()-1;i!=j;i++,j--){
        if(s[i]!=s[j]) ans++;
    }
    cout<<ans;
    return 0;
}
