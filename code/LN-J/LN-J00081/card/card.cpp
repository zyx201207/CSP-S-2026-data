#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int ans[300001];
int bj;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            if((n-i+1)%2!=0){
                ans[a[i]]+=1;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else{
        bj=1;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                b[bj++]=a[j];
                int k=bj-1;
                while(k>0){
                    k--;
                    if(b[k]==a[j]){
                        break;
                    }
                }
                if(k!=0){
                    for(int w=k;w<bj;w++){
                        b[w]=0;
                    }
                    bj-=(bj-k);
                }
            }
            for(int j=1;j<bj;j++){
                ans[b[j]]++;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
