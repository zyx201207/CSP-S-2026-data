#include<bits/stdc++.h>
using namespace std;
int n,m,len,t[500005],ans[300005],a[500005],l=1,r=1;
string s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&t[i]);
    }
    for(int i=1;i<=n;i++){
        l=1,r=1;
        for(int j=i;j<=n;j++){
            a[r]=t[j];
            r++;
        }
        for(int j=i;j<=n;j++){
            for(int k=l;k<=r;k++){
                if(a[k]==t[j]){r=k-1;break;}
            }
            a[++r]=t[j];
        }
        for(int j=l;j<=r;j++){
            ans[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
