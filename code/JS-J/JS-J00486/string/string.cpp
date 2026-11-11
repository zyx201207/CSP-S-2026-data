#include<bits/stdc++.h>
using namespace std;
int n,a[2000005],ans=0;
char s[2000005];
int main(){
    freopen("string.in","r",stdin);freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char st;
        cin>>a[i];
        cin>>st;
        for(int j=a[i-1];j<=a[i];j++){
            s[j]=st;
        }
    }
    for(int i=1;i<=n;i++){
        if(s[i]!=s[n-i+1])ans++;
    }
    cout<<ans;
    return 0;
}
