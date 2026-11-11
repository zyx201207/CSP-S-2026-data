#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int ans=0;
int cnt=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    s+=' ';
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int i=1;i<=a;i++)s+=c;
        ans+=a;
    }
    for(int i=1,j=ans;i<=ans/2;i++,j--){
        if(s[i]!=s[j])cnt++;
    }
    cout<<cnt;
}
