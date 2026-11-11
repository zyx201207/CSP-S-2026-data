#include<bits/stdc++.h>
using namespace std;
int n;
int ans=0, ad=0,j=0;
long long s[1000100];
char a[1000100];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>a[i];
        if(a[i]=='a'){
            ad++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]=='c'){
            j++;
            ans+=s[i];

        }
    }
    if(j<ad) ans+ad-j;
    cout<<ans;
    return 0;
}







