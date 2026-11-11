#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    int t=0;
    for(int i=1;i<=n;i++){
        int x;
        char abc;
        cin>>x>>abc;
        for(int j=1;j<=x;j++){
            t++;
            s[t]=abc;
        }
    }
    int m=(t+1)/2;
    int l=0;
    for(int i=1;i<=m;i++){
        if(s[i]!=s[t-i+1]){
            l++;
        }
    }
    cout<<l<<endl;
}