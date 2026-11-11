#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m,q=0;
    string s;
    char p;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m>>p;
        for(int i=1;i<=m;i++)s+=p;
    }
    string s1=s;
    reverse(s1.begin(),s1.end());
    for(int i=0;i<s.size();i++){
        if(s[i]==s1[i])q++;
    }
    cout<<(s.size()-q)/2;
    return 0;
}
