#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int n,d,maxr=-1,minl=1000006;
int f(int l,int r){
    if(l==r) return 1;
    int sum=0;
    for(int i=1;i<r;i++){
        if(a[i]-a[l]<=d) sum+=f(l+1,r);
        else return sum;
    }
    return sum;
}
int main(){
    freopen("mlgrate.in","r",stdin);
    freopen("mlgrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int awa=1;awa<=t;awa++){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        int cntt=0;
        for(int l=1;l<=n;l++){
            for(int r=l+2;r<=n;r++){
                int sd=f(l,r);
                if(maxr<r||minl>l&&sd==2){
                    maxr=r;
                    minl=l;
                    cntt++;
                }
            }
        }
        cout<<cntt<<"\n";
    }
    return 0;
}
