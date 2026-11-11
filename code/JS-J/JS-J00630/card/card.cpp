#include<bits/stdc++.h>
#define ll long long

using namespace std;
int a[500010];
ll ans[300010];
bool f[300010]={0};
int q[300010];
int pos[300010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);freopen("card.out","w",stdout);//read,write
    //don`t forget!!!!
    int n,m;
    cin>>n>>m;
    int cnt;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cnt=0;
        for(int j=i;j<=n;j++){
            if(!f[a[j]]){
                f[a[j]]=1;
                q[++cnt]=a[j];
                pos[a[j]]=cnt;
            }
            else{
                for(int k=pos[a[j]]+1;k<=cnt;k++){
                    f[q[k]]=0;
                    pos[q[k]]=-1;
                }
                cnt=pos[a[j]];
            }
            //for(int k=1;k<=cnt;k++)cout<<q[k]<<" ";
        }
        for(int j=1;j<=cnt;j++){
            //cout<<q[j]<<" ";
            ans[q[j]]++;
            f[q[j]]=0;
            pos[q[j]]=-1;
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}