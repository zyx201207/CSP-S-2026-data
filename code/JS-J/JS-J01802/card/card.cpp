#include <bits/stdc++.h>
using namespace std;
int n,m;
int p[200001];
int zm[200001];
int t[200001];
int zt[200001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);


    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>p[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            zm[j]=p[j];
            t[p[j]]++;
            if(t[p[j]]>1){
                for(int th=j-1;th>0;--th){
                    zm[th]=0;
                }
                t[p[j]]--;
                for(int hh=1;hh<=100000;hh++){
                    if(hh!=p[j]){
                        t[hh]=0;
                    }
                }
            }
        }
        for(int j=1;j<=100000;j++){
            zt[zm[j]]++;
            zm[j]=0;
            t[j]=0;
        }
    }

    for(int i=1;i<=100000;i++){
        if(zt[i]!=0){
            cout<<zt[i]<<' ';
        }
    }
    return 0;
}
