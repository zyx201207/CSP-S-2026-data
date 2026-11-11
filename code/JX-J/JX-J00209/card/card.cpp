
#include<bits/stdc++.h>
using namespace std;
struct m{
    int k,l;//l shi wei zhi;
};

int a[500005],wv[500005];
m to[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            to[a[j]].k++;
            if(to[a[j]].k==1){
                to[a[j]].l=j;
            }
            else if(to[a[j]].k==2){
                for(int p=to[a[i]].l;p<=j;p++){
                    to[a[p]].k=0;
                }
                to[a[j]].k++;
                to[a[j]].l=j;
            }
        }
        for(int j=1;j<=n;j++){
            if(to[a[j]].k>=1){
                wv[a[j]]++;
            }
            to[j].k=0;
            to[j].l=0;
        }
    }
    for(int i=1;i<=m;i++){
        if(i==a[n]){
            cout<<n<<" ";
            continue;
        }
        cout<<wv[a[i]]<<" ";
    }

    return 0;
}
