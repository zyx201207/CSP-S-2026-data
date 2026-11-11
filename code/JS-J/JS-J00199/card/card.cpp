#include<iostream>
#include<cstring>
using namespace std;
int a[500005],b[300005];
bool b1[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(b1,0,sizeof(b1));
        for(int j=i;j<=n;j++){
            if(b1[a[j]]==1){
                int k=j-1;
                while(a[k]!=a[j]){
                    b1[a[k]]=0;
                    k--;
                }
                b1[a[k]]=0;
            }
            b1[a[j]]=1;
        }
        for(int k=1;k<=m;k++){
            if(b1[k]==1){
                b[k]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}
