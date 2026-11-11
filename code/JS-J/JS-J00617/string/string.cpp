#include<bits/stdc++.h>
using namespace std;
int n,a[50010];
long long ans=0,o=0;
char s[50010];
string S;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>s[i];
    }
    for(int i=0;i<n;i++){
        ans+=a[i];
        for(int j=0;j<a[i];j++){
            S+=s[i];
        }
    }
    if(ans%2==0){
        for(long long i=0;i<ans/2;i++){
            if(S[i]!=S[ans-i-1]){
                o++;
            }
        }
    }
    else{
        for(long long i=0;i<(ans-1)/2;i++){
            if(S[i]!=S[ans-i-1]){
                o++;
            }
        }
    }
    cout<<o;
    return 0;
}
