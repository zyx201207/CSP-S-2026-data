#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int b1[200005];
long long ans;
int b[25];
bool cmp(int x,int y){
    return x>y;
}
int baoli(int z,int g){
    int anss=0;
    if(g==1+m){
        int ansn=b[1];
        for(int i=1;i<=m;i++){
            ansn&=b[i];
        }
        return ansn;
    }
    if(z+1>n)return 0;
    for(int i=z;i<=n;i++){
        b[g]=a[i];
        if(baoli(i+1,g+1)>anss)anss=baoli(i+1,g+1);
    }
    return anss;
}
int baolii(int z,int g){
    int anss=0;
    if(g==1+m){
        int ansn=b1[1];
        for(int i=1;i<=m;i++){
            ansn&=b1[i];
        }
        return ansn;
    }
    if(z+1>n)return 0;
    for(int i=z;i<=n;i++){
        b1[g]=a[i];
        int t=baoli(i+1,g+1);
        if(t>anss)anss=t;
    }
    return anss;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,cmp);
    if(m==1){
        cout<<a[1];
        return 0;
    }
    if(a[1]<4){
        int a1,a2,a3;
        for(int i=1;i<=n;i++){
            if(a[i]==1)a1++;
            if(a[i]==2)a2++;
            if(a[i]==3)a3++;
        }
        if(m<=a3){
            cout<<3;
            return 0;
        }
        if(m<=a3+a2){
            cout<<2;
            return 0;
        }
        if(m<=a3+a1){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    if(m==2){
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(a[i]&a[j]>ans){
                    ans=a[i]&a[j];
                    if(ans==a[i]){
                        cout<<ans;
                        return 0;
                    }
                }
            }
        }
    }
    if(m==n){
        ans=a[1];
        for(int i=1;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        for(int i=1;i<=n;i++){
            long long ansn;
            if(i==n){
                ansn=a[1];
            }else
                ansn=a[i+1];
            for(int j=1;j<=n;j++){
                if(j!=i)ansn&=a[j];
            }
            ans=max(ans,ansn);
        }
        cout<<ans;
        return 0;
    }
    if(n<=20){
        cout<<baoli(1,1);
    }else{
        cout<<baolii(1,1);
    }
    return 0;
}
