#include<bits/stdc++.h>
using namespace std;
int a[600000],b[600000];
int cnt[400000];
void be0(int r, int l){
    for(int i=r;i<=l;i++){
        b[i]=0;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        be0(1,n);
        int sum=0;
        for(int i=k;i<=n;i++){
            b[i] = a[i];
            for(int j=1;j<i;j++){
                if(b[j]==b[i]){
                    be0(j,i-1);
                    break;
                }
            }
        }
        for(int i=k;i<=n;i++){
            if(b[i] != 0) cnt[b[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
