#include <bits/stdc++.h>
using namespace std;
long long n;
long long gg(string x){
    long long ww[105],nt=0-3;
    for(int i=0;i<105;i++){
        ww[i]=0;
    }
    for(int i=0;i<x.size();i++){
        ww[x[i]]=1;
    }
    for(int i=int('a');i<=int('z');i++){
        if(ww[i]==1) nt++;
    }



    if(nt==1){
        return 0;

    }
    return nt;
}
int main(){
    freopen("string.in","s",stdin);
    freopen("string.out",stdout);
    cin>>n;
    string a[n+5],S="";
    long long cnt[n+5];
    for(int i=0;i<n;i++){
        cin>>cnt[i]>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<cnt[i];j++){
            S+=a[i];
        }
    }

    cout<<gg(S);



    return 0;
}
