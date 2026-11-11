#include <bits/stdc++.h>
using namespace std;
int x[10005],a[10005]={0},s[10005]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<=m;j++){
            a[x[j]]++;
            if(a[x[j]]>1){
                for(int k=0;k<=j;k++)if(a[k]>0)a[k]--;
            }
        }
        for(int j=0;j<1000;j++){
            if(a[j]==0)continue;
            s[j-1]+=a[j];
        }
    }
    for(int i=0;i<=m;i++){
        cout<<s[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
