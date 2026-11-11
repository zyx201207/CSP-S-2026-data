#include<bits/stdc++.h>
using namespace std;
int n,m,a[15],r[15],v[15],ans[15];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v[i]=a[i];
    }
    sort(v+1,v+1+n);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(v[i]!=v[i-1]){
            cnt++;
        }
    }
    for(int s=1;s<=n;s++){
        int cnt=n-s+1;
        int res=s;
        while(cnt==0){
        r[res]=a[res];
        if(res!=1){
            for(int i=1;i<=res;i++){
                if(r[i]==r[res]){
                    for(int j=1;j<=res;j++){
                        r[j]=0;
                    }
                }
            }
        }
    }
    for(int w=1;w<=cnt;w++){
        for(int i=1;i<=res;i++){
            if(a[w]==r[res]){
                ans[w]++;
            }
        }
    }
    }
    for(int i=1;i<=cnt;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
