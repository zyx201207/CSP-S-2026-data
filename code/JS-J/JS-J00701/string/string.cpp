#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n,m[200010],f=0;
    char a[200010];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i]>>a[i];
        if(m[i]>1000){f=1;break;}
    }
    if(f==0){
    for(int i=1;i<=n;i++){
       for(int j=1;j<=m[i];j++)s=s+a[i];
    }
    int j=s.size(),ans=0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[j-1])ans++;
            j--;
    }
    cout<<ans;
    }
    else{
        int q=n;
        for(int i=2;i<=n;i++)cin>>m[i]>>a[i];
        long long ans2=0;
        for(int i=1;i<=n/2;i++){
            if(a[i]!=a[q])ans2+=m[i];
            q--;
        }
        cout<<ans2;
    }
    return 0;
}
