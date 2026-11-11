#include<bits/stdc++.h>
using namespace std;
int n;
int a[200003],ans=0;
char c[200003];
char s[89999999];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    int sum=0;
    int j;
    for(int i=1;i<=n;i++){
        for(j=1+sum;j<=a[i]+sum;j++){
            s[j]=c[i];
        }
        sum+=a[i];
    }
    for(int i=1;i<=n/2+1;i++){
        if(s[j+1-i]!=s[i])ans++;
    }
    cout<<ans;
    return 0;
}