#include<bits/stdc++.h>
using namespace std;
int n,a,qwe,cnt;
string ans;
char q;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>q;
        for(int i=1;i<=a;i++){
            ans[qwe+i]=q;
        }
        qwe+=a;
    }
    for(int i=1;i<=qwe/2;i++){
        if(ans[i]!=ans[qwe-i+1])cnt++;
    }
    cout<<cnt;
return 0;
}
