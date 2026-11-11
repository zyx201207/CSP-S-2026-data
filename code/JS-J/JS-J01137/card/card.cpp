#include<bits/stdc++.h>
using namespace std;
int a[500005],t[300005]={0};
int zhai[500005],jzd=1;
bool book[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(book[a[j]]==0){
                book[a[j]]=1;
                zhai[jzd++]=a[j];
            }
            else{
                while(zhai[jzd-1]!=a[j]){
                    jzd--;
                    book[zhai[jzd]]=0;
                }
            }
        }
        for(int j=1;j<jzd;j++){
            t[zhai[j]]++;
            book[zhai[j]]=0;
        }
        jzd=1;
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<' ';
    }
    return 0;
}
