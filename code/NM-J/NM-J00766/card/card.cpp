#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],l[500005],ans[300005],maxn=-1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        maxn=max(maxn,a[i]);
        int w=1;
        for(int j=i;j<=n;j++){
            l[w]=a[j];
            if(w>=2){
                for(int k=1;k<w;k++){
                    if(l[k]==l[w]){
                        int s=w;
                        for(int x=k;x<=s;x++){
                            l[x]=0;
                            w--;
                        }
                        w++;
                        l[w]=a[j];
                    }
                }
            }
            w++;
        }
        for(int j=1;j<=w-1;j++)
            ans[l[j]]++;
    }
    for(int i=1;i<=maxn;i++){
        cout<<ans[i]<<' ';
}
    return 0;
}
