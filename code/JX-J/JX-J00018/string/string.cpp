#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    int j=s.size()-1;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[j]) ans++;
        j--;
    }
    cout<<ans;
    return 0;
}

