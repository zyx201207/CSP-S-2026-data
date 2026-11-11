#include<bits/stdc++.h>
using namespace std;
int n,ans=0,j=0;
char c;
char s[100000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1,k;i<=n;i++){
        cin>>k>>c;
        while(k--){
            s[j++]=c;
        }
    }
    for(int i=0;i<j;i++){
        cout<<s[i];
    }
    for(int i=0;i<j/2;i++){
        if(s[i]!=s[j-i-1])ans++;
    }
    cout<<ans;
    return 0;
}
