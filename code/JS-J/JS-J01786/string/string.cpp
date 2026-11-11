#include<bits/stdc++.h>
using namespace std;
string s="";
long long n,ans=0;
void m(string x){
    int l=0,r=x.size()-1;
    while(l<r){
        if(x[l]!=x[r])ans++;
        l++;
        r--;
    }
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char b;
        cin>>a>>b;
        for(int j=1;j<=a;j++)s+=b;
    }
    m(s);
    cout<<ans;
    return 0;
}
