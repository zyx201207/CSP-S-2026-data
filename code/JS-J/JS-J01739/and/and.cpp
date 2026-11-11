#include<bits/stdc++.h>
using namespace std;
int n,m,mx,bmn=31,bh[31];
struct p{
    int n;
    bool b[31];
}a[200005];
bool cmp(p a,p b){
    for(int i=mx;i>=0;i--){
        if(a.b[i]!=b.b[i]){
            return a.b[i];
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].n;
        long long ac=a[i].n,k=2;
        for(int j=0;j<=30;j++){
            if(ac==k/2){
                a[i].b[j]=1;
                bh[j]++;
                ac-=k/2;
                bmn=min(bmn,j);
                break;
            }
            if(ac>=k&&ac%k){
                a[i].b[j]=1;
                ac-=k/2;
                bh[j]++;
            }
            k*=2;
        }
    }
    for(int i=30;i>=0;i--){
        mx=i;
        if(bh[i]>=m){
            sort(a+1,a+n+1,cmp);
            mx=a[1].n;
            for(int j=2;j<=m;j++){
                mx=(mx&a[j].n);
            }
            cout<<mx;
            return 0;
        }
    }
    cout<<0;
    return 0;
}
