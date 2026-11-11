#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen(card.in,"r","stdin");
    freopen(card.out,"w","stdout");
    long long a,b;
    cin>>a>>b;
    long long c[a]={0},z[b+5]={0};
    for(long long i=0;i<a;i++){
        cin>>c[i];
    }
    for(int i=0;i<a;i++){
        long long w=0;
        long long q[a-i]={0},d[a]={0};
        for(long long j=i;j<a;j++){
            if(d[c[j]]==0){
                d[c[j]]=1;
                q[w]=c[j];
                w++;
            }else{
                while(q[w]!=c[j]){
                    d[q[w]]=0;
                    q[w]=0;
                    w--;
                }
                q[w]=c[j];
                w++;
            }
        }
        for(long long j=0;j<w;j++){
            z[q[j]]++;
        }
    }
    for(long long i=1;i<=b;i++){
        cout<<z[i]<<" ";
    }
    return 0;
}
