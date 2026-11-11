#include<bits/stdc++.h>
using namespace std;
int n,k=0;
long long cnt=0;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        k+=a;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    for(int i=1;i<=(s.size()/2);i++){
        if((s[i]-'a')!=(s[s.size()-1]-'a')){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
