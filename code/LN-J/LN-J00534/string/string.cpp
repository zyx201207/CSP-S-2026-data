#include<bits/stdc++.h>
using namespace std;
int a[200005],c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,l=0,ans=0;
    string s="";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        l+=a;
        while(a--){
            s+=c;
        }
    }
    string s1=reverse(s,s+l);
    for(int i=0;i<l/2;i++){
        if(s[i]!=s1[i])ans++;
    }
    cout<<ans;
}