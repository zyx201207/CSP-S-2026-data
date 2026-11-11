#include<bits/stdc++.h>
using namespace std;

long long a[500005];
long long s[500005];
long long k[300005]={0};

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>s[i];
    }
    for(long long i=1;i<=n;i++){
        long long i1=1;
        for(long long j=i;j<=n;j++){
            int p=0;
            for(long long o=1;o<i1;o++){
                if(a[o]==s[j]){
                    p=1;
                    for(long long w=o;w<i1;w++){
                        a[w]=0;
                    }
                    i1=o+1;
                    a[i1++]=s[j];
                    break;
                }
            }
            if(p==0){
                a[i1++]=s[j];
            }
        }
        for(long long j=1;j<=m;j++){
            for(long long o=1;o<i1;o++){
                if(a[o]==j){
                    k[j]++;
                    break;
                }
            }
        }
        memset(a,0,sizeof(a));
    }
    for(long long i=1;i<=m;i++){
        cout<<k[i]<<" ";
    }
    cout<<endl;
    return 0;
}