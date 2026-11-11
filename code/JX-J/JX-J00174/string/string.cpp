#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,x[N];
char a[N];
string str;
bool huiwen(string s){
    string a;
    int j=s.size()-1;
    for(int i=0;i<s.size();i++){
        a[i]=s[j];
        j--;
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=s[i])return false;
    }
    return true;
}
void io(){
    int ans=0;
    for(int i=0;i<=str.size()/2;i++){
        if(str[i]!=str[str.size()-i-1])ans++;
    }
    cout<<ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>a[i];
        for(int i=1;i<=x[i];i++)str+=a[i];
    }
    bool flag=1;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1]){
            flag=0;
            break;
        }
    }
    if(flag){
        cout<<0;
        return 0;
    }
    else{
        if(huiwen(str))cout<<0;
        else {
            io();
        }
    }
    return 0;
}
