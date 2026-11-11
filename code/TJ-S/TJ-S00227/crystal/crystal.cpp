#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],s[N];
long long d[N],n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=a[i]-a[i-1];
        if(i>1){
            d[i]=(d[i-1]+s[i]);
        }
    }
    long long mx=-1;
    for(int i=1;i<n;i++){
        int l=i,r=n;
        long long srl=d[l];
        bool flag=false;
        for(int j=15;j>=0;j--){
            if(r-l+1<=mx){
                flag=true;
                break;
            }
            if(pow(2,j)>=r){
                continue;
            }
            long long srr=d[r-int(pow(2,j))];
            if(srr-srl>m){
                r-=pow(2,j);
            }
        }
        if(flag){
            continue;
        }
        if(r-l>mx){
            mx=r-l;
        }
    }
    cout<<mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
