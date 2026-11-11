#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long ans[200005],b,c[32];
bool cmp(int x,int y){
    return x>y;
}

vector <int> v[32];/*
void f(int x,int i){
    int cnt=1;
    while(x>0){
        if(x%2==1) ans[i][cnt]++,v[cnt].push_back(i);
        cnt++;
        x/=2;
    }
}*/
int a1,a2,a3;
int main(){
     freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
    cin>>n>>m;
    bool flag1=1,flag2=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i-1){
            flag1=0;
        }
        if(a[i]>=4){
            flag2=0;
        }
        if(a[i]==1){
            a1++;
        }
        if(a[i]==2){
            a2++;
        }
        if(a[i]==3){
            a3++;
        }
    }
    b=a[1];
    sort(a+1,a+n+1,cmp);
    if(m==1) {
        cout<<a[1];
        return 0;
    }
    if(m==2){
            int maxn=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    if(i!=j){
                        maxn=max(maxn,a[i]&a[j]);
                    }

            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            b&=a[i];
        }
        cout<<b;
        return 0;
    }
    if(flag2){
        if(a3>=m){
            cout<<3;
        }
        else if(a2+a3>=m){
            cout<<2;
        }
        else if(a3+a1>=m){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            b&=a[i];
        }
        cout<<b;
        return 0;
    }


}
