#include <bits/stdc++.h>
using namespace std;

int a[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    bool pd = true;
    long long cf;
    long long lsls=0;
    if(n==1){
        cout<<"1"<<endl;
        return 0;
    }
    for(int i = 1;i<=n;i++){
        long long lslsls;
        cin>>lslsls;
        if(lsls<=1e9)
            a[i]=lslsls;
        if(i==2){
            cf=lslsls-lsls;
        }
        if(lslsls-lsls!=cf&&i>=2){
            pd=false;
        }
        lsls=lslsls;
    }
    if(cf==0){
        cout<<n<<endl;
        return 0;
    }
    if(pd){
        long long k=2*m/cf;
        long long xx = (1+sqrt(4*k+1))/2;
        cout<<xx<<endl;
        return 0;
    }
    
    sort(a+1,a+n+1);
    int qzh[500005];
    qzh[0]=0;
    for(int i = 1;i<=n-1;i++){
        qzh[i]=qzh[i-1]+a[i+1]-a[i];
    }
    for(int i = n-1;i>=0;i--){
        int mi=1e9;
        int lsx;
        for(int j = 1;j<=n-i;j++){
            if(mi>=qzh[j+i-1]-qzh[j-1]){
                mi=qzh[j+i-1]-qzh[j-1];
                lsx=j;
            }
        }
        long long cnt=0;
        for(int j = lsx;j<lsx+i;j++){
            cnt+=(qzh[j]-qzh[j-1])*j;
        }
        if(cnt<=m){
            cout<<i+1<<endl;
            return 0;
        }
    }
    return 0;
}