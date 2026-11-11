#include<bits/stdc++.h>
using namespace std;
int m,n;
long long aa[200005];//which is the num cin;
long long a[200005];//which is the num's count;
long long ans=0;
void A(int cnt,long long anss,int nmb){
    if(cnt>=m){
        ans=max(ans,anss);
        return;
    }for(int i=nmb+1;i<=n;i++){
        A(cnt+1,anss&aa[i],i);
    }
}

int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    long long maxn=0,mn=0;
    for(int i=1;i<=n;i++){
        cin>>aa[i];
        a[aa[i]]++;
    }
    bool b=false;
    for(int i=1;i<=n;i++){
        if(a[aa[i]]>=m&&aa[i]>=aa[mn]){
            maxn=a[aa[i]];
            mn=i;
            b=true;
        }
    }if(b==true){
        cout<<aa[mn];
        return 0;
    }
    for(int i=1;i<=n;i++){
        A(1,aa[i],i);
    }cout<<ans;

}
