#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
const int M=3*1e5+5;
int n,m;
int c[N];
int sh[N][M];
int desk[N];
bool finds(int a,int de){
    for(int i=1;i<=de;i++){
        if(desk[i]==a) return true;
    }
    return false;
}
int finding(int a,int de){
    for(int i=1;i<=de;i++){
        if(desk[i]==a) return i;
    }
    return -1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }

    int de=0;
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            if(!finds(c[i],de)){
                desk[i]=c[i];
                de++;
            }
            else{
                int w=finding(c[i],de);
                for(int j=w;j<=de;j++){
                    de--;
                }
                desk[de+1]=c[i];
            }

        }
        for(int i=1;i<=de;i++){
           sh[k][i]=desk[i];
        }
    }
    for(int k=1;k<=m;k++){
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sizeof(sh[i]);j++){
                if(sh[i][j]==k) cnt++;
            }
        }
        cout<<cnt<<" ";

    }
    return 0;
}
