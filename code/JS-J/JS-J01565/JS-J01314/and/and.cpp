#include <bits/stdc++.h>
using namespace std;

int arr[200005];
int maxn3=0,n,m;

void choose(int res,int nu,int k){
    if(nu==m){
        maxn3=max(maxn3,res);
        return;
    }
    for(int i=k;i<=n && i+(m-nu)-1<=n;i++){
        choose((nu==0 ? arr[k] : (res & arr[k])),nu+1,k+1);
        choose(res,nu,k+1);
    }
}

int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int maxn=0,sum;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        maxn=max(maxn,arr[i]);
        if(i==1){
            sum=arr[i];
        }
        else{
            sum=sum & arr[i];
        }
    }

    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(m==n){
        cout<<sum;
        return 0;
    }
    if(m==2){
        int maxn2=0;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                maxn2=max((arr[i] & arr[j]),maxn2);
            }
        }
        cout<<maxn2;
        return 0;
    }
    else{
        choose(0,0,1);
        cout<<maxn3;
    }
    return 0;
}