#include<bits/stdc++.h>
using namespace std;
int a[200005],c[1000];
char b[200005],d[200005],e[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=-1,num;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        c[b[i]-'a']+=a[i];
        for(int j=1;j<=a[i];j++){
            e[++sum]=b[i];
        }
    }
    if(sum%2!=0) num=(n-1)/2;
    else num=n/2;
    for(int i=0;i<=25;i++){
        if(c[i]==0) continue;
        if(c[i]%2==0){
            for(int j=1;j<=c[i]/2;j++){
                d[num]=char(i+97);
                d[n-num+1]=d[num];
                num--;
            }
        }
        else{
            d[(n+1)/2]=char(i+97);
            for(int j=1;j<=(c[i]-1)/2;j++){
                d[num]=char(i+97);
                d[n-num+1]=d[num];
                num--;
            }
        }
    }
    long long tot=0;
    for(long long i=0;i<=sum;i++){
        if(e[i]!=d[i]) tot++;
    }
    cout<<tot/2;
    return 0;
}
