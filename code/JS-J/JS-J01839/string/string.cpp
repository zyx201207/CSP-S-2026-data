#include<bits/stdc++.h>
using namespace std;
long long n,num[200000],l,ans;
string str[200000];
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i]>>str[i];
        for(int j=0;j<num[i];j++)s+=str[i];
        l+=num[i];
    }
    for(long long i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1])ans++;
    }cout<<ans;
    return 0;
}
