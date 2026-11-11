#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        char a;
        cin>>a;
        for(int j=1;j<=x;j++){
            s+=a;
        }
    }
    for(int i=1;i<=(s.size()-1)/2;i++){
        if(s[i-1]!=s[(s.size()-1-i)]) cnt++;
    }
    cout<<cnt;
    return 0;
}
