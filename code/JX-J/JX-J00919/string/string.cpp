#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    string S="";
    char c;
    long long n,a;
    long long len,ans=0;
    cin>>n;

    for(long long i=1;i<=n;i++){
        cin>>a>>c;
        for(long long j=1;j<=a;j++){
            S+=c;
        }
    }
    len=S.size();

    if(len%2==0){
        for(long long i=0;i<len/2;i++){
            if(S[i]!=S[len-1-i]){ans++;}
        }
    }
    else{
        for(long long i=0;i<(len-1)/2;i++){
            if(S[i]!=S[len-1-i]){ans++;}
        }
    }

    cout<<ans<<S;

    return 0;
}
