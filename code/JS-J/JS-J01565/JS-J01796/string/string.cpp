#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("string,in","r",stdin);
    freopen("string.out","w",stdout);

    string s="";
    int n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long num;
        char c;
        cin>>num>>c;
        for(long long j=1;j<=num;j++){
            s+=c;
        }
    }
    long long l=0,r=s.size()-1,cnt=0;
    while(r>=l){
        if(s[l]!=s[r]){
            cnt++;
        }
        l++;
        r--;

    }
    cout<<cnt;

    return 0;
}
