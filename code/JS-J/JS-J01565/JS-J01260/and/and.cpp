#include<bits/stdc++.h>
using namespace std;
int a[200005];
int f[200005];
int o[5];
int p[25];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int sum=0;
    int maxn=0;
    int k=0;
    bool q=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(q){
            bool b=true;
            for(int j=0;j<=20;j++){
                int y=pow(2,j);
                if(y&a[i]==0){
                    b=false;
                }if(!b&&y&a[i]!=0){
                    q=false;
                    break;
                }
            }
        }
        for(int j=0;j<=20;j++){
            int u=pow(2,j);
            if(a[i]&u==u)p[j]++;
        }
        if(a[i]<=4)o[a[i]]++;
        if(i==1){
            sum=a[i];
        }else{
            sum=sum&a[i];
        }maxn=max(maxn,a[i]);
    }int mn=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            mn=max(mn,a[i]&a[j]);
        }
    }f[n]=sum;f[1]=maxn;f[2]=mn;
    if(m==n){
        cout<<sum;
        return 0;
    }else if(m==1){
        cout<<maxn;
        return 0;
    }
    else if(m==2){cout<<mn;
    return 0;}
    else if(maxn<=4){
        if(o[4]>=m)cout<<4;
        else if(o[3]>=m)cout<<3;
        else if(o[3]+o[2]>=m)cout<<2;
        else if(o[3]+o[1]>=m)cout<<1;
        else{
            cout<<0;
        }return 0;
    }else if(m==n-1){
        for(int i=1;i<=n;i++){
                int u=2147483647;
            for(int j=1;j<=n;j++){
                if(j!=i)u=u&a[j];
            }k=max(k,u);
        }cout<<k;
        return 0;
    }
    else if(q){
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
        return 0;
    }cout<<0;
    return 0;
}
