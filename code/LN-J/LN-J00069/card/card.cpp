#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+10]={},b[n+10]={},sum[n+10]={},q=0,summ=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            b[j]=0;
        q=0;
        for(int j=i;j<=n;j++){
            summ=0;
            for(int z=1;z<=j-1;z++)
                if(b[z]==a[j]){
                    q=z;
                    summ=1;
                    break;
                }
            if(summ==1)
                for(int z=q;z<=j-1;z++)
                    b[z]=0;
            b[j]=a[j];
        }

        for(int j=i;j<=n;j++)
            sum[b[j]]++;
    }
    for(int i=1;i<=m;i++)
        cout<<sum[i]<<" ";
    return 0;
}
