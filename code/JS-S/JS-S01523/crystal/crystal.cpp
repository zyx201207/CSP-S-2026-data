#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
long long f[10005][10005];
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int fm=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=3){
            if((a[i]-a[i-1]!=a[i-1]-a[i-2])){
                fm=1;
            }
        }
    }
    if(fm==0){
        int c=a[2]-a[1];
        int g=m/c;
        int h=1,k=0;
        while(g>=h){
            g-=h;
            k++;
            if(g>=h){
                g-=h;
                k++;
            }
            h++;
        }
        cout<<k<<endl;
    }
    else {
        sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            f[i][j]=a[i]-a[j];
        }
    }
    for(int i=1;i<=n;i++){
            int d=0,cnt=0;
        for(int j=i;j>=1;j--){

            if(d+f[i][j]>=m&&f[i][j]!=0){

                ans=max(ans,cnt+1);
                break;
            }
            d+=f[i][j];
            cnt++;
        }
    }
     cout<<ans<<endl;
    }

    return 0;
}
