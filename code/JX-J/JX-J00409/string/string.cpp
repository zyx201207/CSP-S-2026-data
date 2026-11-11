#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long m;
        char c;
        cin>>m>>c;
        for(int j=1;j<=m;j++){
            s+=c;
        }
    }
    long long cnt=0,len=s.size();
    for(long long k=0;k<len/2+1;k++){
        if(s[k]!=s[len-k-1]){
            s[len-k-1]=s[k];
            cnt++;
        }
    }
    cout<<cnt;
}
