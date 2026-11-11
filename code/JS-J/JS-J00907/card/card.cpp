#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],cnt[M],table[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(table,0,sizeof(table));
        for(int j=i;j<=n;j++){
            for(int k=1;k<=j-i+1;k++){
                if(table[k]==a[j]){
                    for(int l=k;l<j-i+1;l++){
                        table[l]=0;
                    }
                }
            }
            table[j-i+1]=a[j];
        }
        for(int j=1;j<=n-i+1;j++){
            if(table[j]!=0) cnt[table[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
