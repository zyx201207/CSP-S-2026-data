#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m,a[100000],b[100000];
    cin>>n>>m;
    int d[m];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            a[i]=b[k];
            for(int mj=1;mj<=n;mj++){
                if(a[i]==b[mj]){
                    a[i+1]==b[mj];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
           if(a[i]==m){
               d[j]++;
           }
       }
    }
    for(int i=1;i<=m;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}
