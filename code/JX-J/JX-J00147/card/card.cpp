#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,have[N],q[N],sum[N];
struct node{
    int k,xb;
}a[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].k;
        if(have[a[i].k]!=0) a[i].xb=have[a[i].k];
        have[a[i].k]=i;
    }
    for(int i=1;i<=n;i++){
        int l=i,s=0;
        for(int j=i;j<=n;j++){
            if(a[j].xb>=i){
                int k=l-1;
                while(q[k]!=q[l]){
                    k--;
                }
                q[k]=a[j].k;
                l=k+1;
                l++;
            }else{
                q[l]=a[j].k;
                l++;
            }
        }
        for(int j=i;j<l;j++){
            sum[q[j]]++;

        }
    }
    for(int i=1;i<=m;i++) cout<<sum[i]<<' ';
    return 0;
}

