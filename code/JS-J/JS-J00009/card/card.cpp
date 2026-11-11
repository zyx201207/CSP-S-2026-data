#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n+2];
    int cnt[n+2];
    int nxt[n+2];
    int lst[m+5];
    memset(cnt,0,sizeof(cnt));
    for(int i = 0;i<n;i++){
        scanf("%d",a+i);
    }

    fill(lst,lst+m+1,-1);
    fill(nxt,nxt+n+1,-1);
    for(int i = 0;i<n;i++){
        if(lst[a[i] ]!=-1){
            nxt[ lst[a[i] ] ] = i;
        }
        lst[a[i]] = i;
    }
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            cnt[a[j]]++;
            while(nxt[j]!=-1){
                j = nxt[j];
            }
        }
    }
    for(int i = 1;i<=m;i++){
        printf("%d " ,cnt[i]);
    }
    return 0;
}
