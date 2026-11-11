#include<bits/stdc++.h>
using namespace std;
/*bool check(long long k,long long n[],long long s,long long l){

}
void solve(){
    long long l=0,r=4e12;
    long long mid=l+(r-l)/2;
    long long n,m,a[2000200];
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    while(l<r){
        mid=l+(r-l)/2;
        sort(a,a+n);
        if(check(mid,a,m,n)){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    cout<<l-1;
}*/
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    long long ans=0;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        long long island[20033];
        for(int j=0;j<n;j++){
            cin>>island[j];
        }
        sort(island,island+n);
        for(int j=0;j<n;j++){
            for(int k=j+3;k<n&&island[k]-island[j]>m&&island[k]-island[j]<2*m;k++){
                bool h=false;
                for(int x=j+1;x<k;x++){
                    if(island[x]+m<island[k]&&island[k]-island[x]<m){
                        h=!h;break;
                    }
                }
                if(!h) break;
                for(int y=k-1;y>j;y--){
                    if(island[y]-m<island[j]&&island[k]-island[y]<m){
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
