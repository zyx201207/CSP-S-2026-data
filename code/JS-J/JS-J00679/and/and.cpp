#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[200010];
bool f1=1;
long long ans,ma=-1,a[200010],k;
int fun(){
    for(int i=1;i<=n;i++){
        k+=f[i];
    }
    return k;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    if(m==1){
        cout<<ma;
        exit(0);
    }else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
            ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }else if(n<=27){
    long long q=1,mad=-1;
    while(f[n+1]!=1){
        ans=-1;
        q=1;
        k=0;
        while(f[q]!=0){
            f[q]=0;
            q++;
        }
        f[q]=1;
        int sum=fun();
        if(sum==m){
            for(int i=1;i<=n;i++){
                if(f[i]){
                    if(ans==-1){
                        ans=a[i];
                    }else{
                        ans&=a[i];
                    }
                }
            }
        }
        mad=max(mad,ans);
    }
    cout<<mad;
    }else{
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
    }
    return 0;
}
