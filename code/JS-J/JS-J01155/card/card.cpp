#include<bits/stdc++.h>
using namespace std;
int n,m,t[300005],t2[300005],x,bjd;
int main(){
    ios::cync_with_stdio(false);
    cin>>tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int a[n+5],b[n+5];
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int y=1;y<=n;y++){
        for(int i=1+bjd;i<=n;i++){
            if(!t[num]){
                t[num]++;
                a[x++]=num;
            }else{
                int xy=0;
                for(int j=0;j<=n;j++){
                    if(xy){
                        t[a[j]]=0;
                    }
                    if(a[j]==num){
                        x=i;
                        xy=1;
                    }

                }
            }
        }
        for(int i=1+bjd;i<=x;i++){
            t2[a[i]]++;
        }
        for(int qw=0;qw<=n;qw++){
            t[qw]=0;
        }
        bjd++;
    }
    for(int i=1;i<=m;i++){
        cout<<t2[i];
    }
    return 0;
}
