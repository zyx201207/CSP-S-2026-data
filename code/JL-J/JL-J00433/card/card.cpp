#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],b[300005],cnt=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    if(m==2){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        for(int k=1;k<=m;k++){
            cnt=0;
            for(int i=1;i<=n;i++){
                a[i]=b[i];
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=i;j++){
                    if(a[i]==a[k]){
                        cnt++;
                    }
                    if(a[i]==a[j]){
                        for(int l=j;l<i;l++){
                            if(a[l]==a[k]){
                                cnt--;
                            }
                        }
                        for(int l=j;l<i;l++){
                            a[l]=0;
                        }
                    }
                }
            }
        }
        cout<<cnt<<" ";
    }
    return 0;
}
