#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int N=100010;
int n;
int a[N];
int x;
string y;
string s[N];
int sum=0;
int tot=0;
bool check(){
    bool flag;
    for(int i=0;i<=tot;i++){
        if(s[i+1]!=s[tot-i]) return false;
        else flag=true;
    }
    return flag;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        for(int j=1;j<=x;j++){
            tot++;
            s[tot]=y;
        }
    }
    int ans=0;
    while(true){
        if(check()==true){
            cout<<sum;
            break;
        }
        if(s[tot-ans]==s[ans]){
            ans++;
            continue;
        }
        s[tot-ans]=s[1+ans];
        ans++;
        sum++;
    }
    return 0;
}
