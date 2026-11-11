#include<bits/stdc++.h>
using namespace std;
int n[10000],t[10000],h[10000],sy[10000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>n[i];
    }
    for(int nb=1;nb<=a;nb++){
            int m[10000];
          for(int i=nb;i<=a;i++){
                m[i]=n[i];
            for(int j=nb;j<i;j++){
                if(m[i]==m[j]&&m[i]!=-1){
                    for(int k=j;k<i;k++){
                        m[k]=-1;
                    }
                }
            }
        }
        for(int i=nb;i<=a;i++){
            if(m[i]!=-1){
                t[m[i]]++;
            }
        }
    }
    for(int i=1;i<=b;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}

