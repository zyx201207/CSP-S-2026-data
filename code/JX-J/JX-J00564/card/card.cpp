#include<bits/stdc++.h>
using namespace std;
bool insane(int c[],int x,int n){
    for(int i=1;i<=n-1;i++){
        if(c[i]==x)return true;
    }
    return false;
}
int main(){
    /*int c[5],f;
    c[0]=0;
    for(int i=1;i<5;i++){
        cin>>c[i];
    }
    cin>>f;
    cout<<insane(c,f,5);*/
    freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    int n,m,cp=1;
    cin>>n>>m;
    int a[n+1],b[n+1],c[n*2]={0},d[m+1]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            b[i]=a[i];
        }
        for(int i=1;i<n*2;i++){
            c[i]=0;
        }
        cp=1;
        for(int j=i;j<=n;j++){
            c[cp]=b[i];
            if(insane(c,b[i],n)){
                c[cp]=0;
                cp--;
                while(c[cp]!=b[i]){
                    c[cp]=0;
                    cp--;
                }
            }
            cp++;
        }
        for(int j=1;j<=m;j++){
            if(insane(c,j,n)){
                d[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}
