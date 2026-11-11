#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500100],c[500100],b[500100],y=1;
bool flag=0;
int main(){
  //  freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        a[i]=b[i];
    }
       for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                for(int w=j;w>=i;w--){
                        if(a[w]==a[j]){
                            y=w;
                            flag=1;
                            break;
                        }
                }
                if(flag==1){
                    for(int w=y;w<=j-1;w++){
                        a[i]=-1;
                    }
                }
                flag=0;
            }
            for(int j=1;j<=m;j++){
                if(a[j]==j){
                    c[j]++;
                }
            }
            for(int j=1;j<=n;j++){
                a[j]=b[j];
            }
       }
       for(int i=1;i<=m;i++){
            cout<<c[i]<<' ';
       }
    return 0;
}
