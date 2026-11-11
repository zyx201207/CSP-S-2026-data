#include<bits/stdc++.h>
using namespace std;
int n,m,root,stop;
int tong[300010];
int a[500010],ans[300010];
int table[500010],memo[300010];
int index=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    root=1,stop=n;
    for(int j=i;j<=stop;j++){
        if(tong[a[j]]){
            for(int k=tong[a[j]]+1;k<root;k++){
                tong[table[k]]=0;
            }
            root=tong[a[j]];
            continue;
        }
        table[root]=a[j];
        tong[a[j]]=root;
        root++;
    }
    for(int j=1;j<=root;j++){
        ans[table[j]]++;
        memo[index++]=table[j];
    }
    stop=1;
    for(int i=n;i>1;i--){
        if(a[i]==a[1]){
            stop=i;
            break;
        }
    }
    for(int i=2;i<=n;i++){]
        for(int j=1;j<=root;j++){
           ans[memo[j]]++;
        }
        for(int j=i;j<=stop;j++){
            if(tong[a[j]]){
                for(int k=tong[a[j]]+1;k<root;k++){
                    tong[table[k]]=0;
                }
                root=tong[a[j]];
                continue;
            }
            table[root]=a[j];
            tong[a[j]]=root;
            root++;
        }
        for(int j=1;j<=root;j++){
            ans[table[j]]++;
            memo[index++]=table[j];
        }
        for(int j=n;j>i;j--){
            if(a[j]==a[i]){
                stop=j;
                break;
            }
        }
        memset(tong,0,sizeof(tong));
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}