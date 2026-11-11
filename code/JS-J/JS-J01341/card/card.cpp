#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[300005],sum[300005];
bool b[300005];
struct Node{
    bool b;
    int sp;
};
Node p[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            p[j].b=0;
            b[j]=0;
        }
        for(int j=i;j<=n;j++){
            if(p[a[j]].b==0){
                p[a[j]].b=1;
                p[a[j]].sp=j;
                b[a[j]]=1;
            }
            else{
                for(int k=p[a[j]].sp;k<j;k++){
                    p[a[k]].b=0;
                    b[a[k]]=0;
                }
                b[a[j]]=1;
                p[a[j]].b=1;
                p[a[j]].sp=j;
            }
        }
        for(int j=1;j<=m;j++){
            if(b[j]==1){
                sum[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
