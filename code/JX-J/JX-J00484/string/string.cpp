#include<bits/stdc++.h>
using namespace std;
int a[200020];
char c[200020];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)s+=c[i];
    }
    long long l=0,r=s.size()-1,ans=0;
    while(l<=r){
        if(s[l]!=s[r])ans++;
        l++;r--;
    }
    cout<<ans;
    return 0;
}
