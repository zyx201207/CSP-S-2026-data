#include<bits/stdc++.h>
using namespace std;
string s;
long long n,cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x=0;char c;
        cin>>x>>c;
        for(int j=1;j<=x;j++){s+=c;}
    }
    int len=s.size()-1;
    for(int i=0,j=len;i<=j,j>=i;i++,j--){
        if(s[i]!=s[j]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
