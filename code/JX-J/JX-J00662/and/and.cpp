#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,z=0,cnt=0;
    int a[200005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxn=0;
    if(m==1){
        for(int i=0;i<n;i++){
            if(a[i]>maxn) maxn=a[i];
        }
        cout<<maxn;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;i++){
            while(a[i]!=1){
                if(a[i]%2==a[j]%2){
                    cnt+=cnt*2*z+a[i]%2;
                    a[i]/2;
                }else{
                    z++;
                }
            }
            maxn=cnt;
            z=0;
        }
        if(cnt>maxn){
            maxn=cnt;
        }
        cnt=0;
    }
    cout<<maxn;
    return 0;
}

