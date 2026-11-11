#include<bits/stdc++.h>
using namespace std;
int t1[500005];
int a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int t[500005]={0};
        int b[500005]={0};
        int l=0;
        for(int j=i;j<=n;j++){
            if(t[a[j]]==0){
                t[a[j]]++;
                l++;
                b[l]=a[j];
            }
            else{
                while(1){
                    if(b[l]==a[j]||l==0){
                        break;
                    }
                    else{
                        t[b[l]]--;
                        l--;
                    }
                }
            }
        }
        for(int k=1;k<=l;k++){
            t1[b[k]]++;
        }
    }
    for(int k=1;k<=m;k++){
        cout<<t1[k]<<" ";
    }
    return 0;
}
