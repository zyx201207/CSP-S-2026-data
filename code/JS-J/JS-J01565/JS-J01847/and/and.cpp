#include<bits/stdc++.h>
using namespace std;
long long n,m,l=1,k[200005],x;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        long long a=k[i],w=0;
        while(a!=0) a=a>>1,w++;
        l=max(w,l);
    }
    for(int i=l-1;i>=0;i--){
        long long cnt=0,ans=0;
        for(int j=1;j<=n;j++){
            if((k[j]>>i)&1==1) cnt++,ans=(ans==0 ? k[j]:ans&k[j]);
        }
        if(cnt==m){
            x=ans;
            break;
        }
        if(cnt>m){
            x=ans;
            for(int j=1;j<=n;j++){
                if(((k[j]>>i)&1)==0) k[j]=0;
            }
        }
    }
    cout<<x;
    return 0;
}

