#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0,sum=0;
    string s;
    cin>>n;
    for(int i = 1;i<=n;i++){
        long a;
        char b;
        cin>>a>>b;
        ans=ans+a;
        for(int j = 1;j<=a;j++)
        s+=b;

    }
    if(ans%2==1){
        for(int i = (ans-1)/2,j=(ans+3)/2;i>=1,j<=ans;i--,j++){
            if(s[i-1]!=s[j-1]){
                sum++;
            }
        }
    }
    else{
        for(int i = ans/2,j=(ans+2)/2;i>=1,j<=ans;i--,j++){
            if(s[i-1]!=s[j-1]){
                sum++;
            }
    }
    }

    cout<<sum;
    return 0;
}
