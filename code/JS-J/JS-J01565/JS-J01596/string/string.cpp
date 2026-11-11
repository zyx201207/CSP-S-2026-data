#include <bits/stdc++.h>
using namespace std;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int m;
    char x;
    int len=0;
    for(int i=1;i<=n;i++){
        cin>>m>>x;
        len+=m;
        for(int j=1;j<=m;j++){
            s+=x;
        }
    }
    len--;
    int cnt=0;
    for(int i=0;i<=len/2;i++){
        if(s[i]!=s[len-i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
