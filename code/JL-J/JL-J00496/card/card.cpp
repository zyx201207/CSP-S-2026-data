#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    string a1;
    long long a[n+1],b[m+1]={0};
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    a1+=' ';
    for(long long i=1;i<=n;i++){
        if(a1.find(char(a[i]+48))==1){
            for(long long j=i;j<=a1.size();j++){
                a1[j]='\0';
            }
        }
        a1[i]+=char(a[i]+48);
        for(long long j=1;j<=a1.size();j++){
            b[a1[j]-48]++;
        }
    }
    for(long long i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}
