#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,lon=0,cnt=0;cin>>n;
string s="";
int nm;string a;
for(int i=1;i<=n;i++){
    cin>>nm;
    cin>>a;
    lon+=nm;
    for(int p=1;p<=nm;p++){
        s+=a;
    }
}
    for(int i=1;i<=lon/2;i++){
        if(s[i-1]!=s[lon-i]){
            cnt++;
        }

    }
    cout<<cnt;

return 0;
}



