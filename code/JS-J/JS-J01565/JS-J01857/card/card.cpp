#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool flag=true;
int qian[500005],cnt[300005],cnt2[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) flag==false;
        cnt2[a[i]]++;
    }
    if(flag==true){
        for(int i=1;i<=m;i++){
            int c=lower_bound(a+1,a+n+1,i)-a;
            cout<<c+cnt2[i]-1<<" ";
        }
    }else{
        for(int i=1;i<=n;i++){
        memset(qian,-1,sizeof(qian));
        for(int j=i;j<=n;j++){
            if(qian[a[j]]==-1) {
                qian[a[j]]=j;
            } else {
                for(int k=qian[a[j]];k<j;k++){
                    qian[a[k]]=-1;
                }
                qian[a[j]]=j;
            }
        }
        for(int l=i;l<=n;l++){
            if(qian[a[l]]==l) {

                cnt[a[l]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    }

    return 0;
}
