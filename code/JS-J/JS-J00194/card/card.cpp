#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int a[maxn],d[maxn];
int m,n;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int c[maxn],b[maxn];
        for(int j=i;j<=m;j++){
            c[i]=a[j];
            b[a[j]]+=1;
            if(b[a[j]]==2){
                for(int e=1;e<i;i++){
                    if(c[e]=c[i]){
                        for(int f=e;f<i;f++){
                            c[f]=0;
                        }
                    }
                    b[a[j]]-=1;
                }
            }
        }
        while(i<=n){
            if(b[i]==0)i++;
            if(b[i]==1)d[b[i]]++;
        }

    }
    for(int i=1;i<=n;i++){
        cout<<d[i]<<" ";
    }

}
