#include<bits/stdc++.h>
using namespace std;
int b[500005]={0};
char a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int maxn=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(a[i]-'0',maxn);
    }
    for(int p=1;p<=n;p++){
    string x="";
    for(int i=p;i<=n;i++){
        if(i>=p+1)x=x+a[i-1];
        int h=-1;
        for(int j=0;j<x.length();j++){
            if(x[j]==a[i])h=j;
        }
        if(h>=0){
            string t=x;
            x="";
            for(int j=0;j<h;j++){
                x=x+t[j];
            }
        }
    }
    x=x+a[n];
    for(int j=0;j<x.length();j++){
        b[x[j]-'0']++;
    }
    }
    for(int i=1;i<=maxn;i++){
        if(b[i]!=0)cout<<b[i]<<" ";
    }
return 0;
}
