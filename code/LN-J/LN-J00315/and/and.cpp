#include<bits/stdc++.h>
using namespace std;
struct node{
    int id,er2;
}a[200005];
int er(int x){
    int t=x;
    int p=0;
    while(t!=0){
        if(t%2==1)p++;;
        t/=2;
    }
    return p;
}
bool cmp(node a,node b){
    if(a.er2>b.er2)return 1;
    else if(a.er2==b.er2){
        if(a.id>b.id)return 1;
        return 0;
    }
    else return 0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].id;
        a[i].er2=er(a[i].id);
    }
    sort(a+1,a+n+1,cmp);
    //for(int i=1;i<=n;i++){
    //    cout<<a[i].id;
    //}
    int ans=a[1].id;
    for(int i=1;i<=m;i++){
        ans=a[i].id&ans;
        //cout<<ans;
        for(int j=i+1;j<=n;j++){
            if(a[j].id==ans)i++;
        }
    }
    cout<<ans;
return 0;
}
