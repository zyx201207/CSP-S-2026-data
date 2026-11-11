#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000010],b[1000010],cnt[1000010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){

            for(int x=1;x<=j;x++){
                if(b[x]==a[j])
                {
                    for(int y=x;y<j;y++)
                        b[y]=0;
                }
            }
            b[j-i+1]=a[j];
        }
        for(int k=1;k<=n;k++){
            if(b[k]!=0)
                cnt[b[k]]++;
        }
        for(int k=1;k<=n;k++)
            b[k]=0;
    }
    for(int i=1;i<=m;i++)
        cout<<cnt[i]<<" ";
    return 0;
}


