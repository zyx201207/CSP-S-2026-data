#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
struct node{
    int us,num;
}a[400000];
bool cmp(node x,node y){
    if(x.us!=y.us){
        return (x.us==0);
    }else
    return x.num>y.num;
}
bool cmp1(node x,node y){
    return x.num<y.num;
}
int sq2[35],num=0;
int check(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=30;j++){
            if(a[i].num==sq2[j]-1){
                a[i].us=1;
                num++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i].us==0)return 0;
    }
    return 1;
}
signed main(){
//    freopen("and.in","r",stdin);
//    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    sq2[0]=1;
    for(int i=1;i<=31;i++){
        sq2[i]=sq2[i-1]*2;
//        cout<<sq2[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
    }
    sort(a+1,a+1+n,cmp1);
    if(check()){
        cout<<a[n].num;
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    m+=num;
    m=min(m,n);
    cout<<a[m].num;
    return 0;
}
