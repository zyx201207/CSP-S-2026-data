#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[200005];
char s[200005];
char t[2000000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)cin>>a[i]>>s[i];
    for(int i=1;i<=n;i++)cout<<a[i]<<s[i];
    for(int i=1;i<=n;i++){
        for(int j=sum;j<=sum+a[i];j++)t[j]=s[i];
        sum+=a[i];
    }
    for(int i=1,j=sum;i<=sum/2;i++,j--){
        if(t[i]!=t[j])ans++;
    }
    cout<<ans;
    return 0;
}
