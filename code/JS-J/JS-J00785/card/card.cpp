#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],cnt[200005],ca[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m;cin>>n>>m;
    ll nn=n;
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++){
        memset(ca,0,sizeof(ca));
        int num=0;
        bool f=0;
        int place=num;
        for(int j=i;j<=nn;j++){
            for(int k=0;k<num;k++){
                if(a[j]==ca[k]){
                    place=k;
                    f=1;
                    break;
                }
            }
            if(f){
                for(int k=place;k<num;k++){
                    ca[k]=0;num--;
                }
            }
            ca[num]=a[j];
            num++;
            //for(int k=0;k<num;k++){
            //    cout<<ca[k]<<" ";
            //}
            //cout<<endl;
        }
        for(int j=0;j<num;j++){
            cnt[ca[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
