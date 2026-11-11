#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[100005],b[100005][100005],s=1,s1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b[s][i+s1]=a[i];
        for(int j=1;b[s][j];j++){
            if(b[s][j]==a[i]){
                for(int d=i;b[s][d];d++){
                    b[s][d]=0;
                }
            }
        }
    }
    for
    return 0;
}
