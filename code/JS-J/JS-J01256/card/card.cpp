#include<bits/stdc++.h>
using namespace std;
struct nm{
    int ans,pr;
};
struct bb{
    int id,ab=0;
};
    nm a[500005];
    bb b[300005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].ans;
        a[i].pr=i+1;
        for(int j=i-1;j>0;j--){
            if(a[j].ans==a[i].ans){
                a[j].pr=i;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;){
            if(a[j].ans==a[j+1].ans||a[j].pr!=j+1){
                j=a[j].pr;
                continue;
            }
            else {
                b[a[j].ans].ab++;
            }
            j++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i].ab<<" ";
    }
    return 0;
}