#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int x[300005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int t[500005]={0},v[300005]={0};
        bool vv[300005]={false};
        int tail=0;
        for(int j=i;j<=n;j++){
            if(tail==0){
                t[0]=a[j];
                v[a[j]]=0;
                vv[a[j]]=true;
                tail++;
            }else{
                tail=(vv[a[j]]==false?tail:v[a[j]]);
                t[tail]=a[j];
                v[a[j]]=tail;
                vv[a[j]]=true;
                tail++;
            }
        }
        for(int j=0;j<tail;j++){
            x[t[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<x[i]<<" ";
    }
    return 0;
}
