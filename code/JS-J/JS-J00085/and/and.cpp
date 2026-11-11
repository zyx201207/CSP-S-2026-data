#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
bool f=1;
int a[200005];
void sol1(){
    int ans=a[1];
    for(int i=2;i<=n;i++){
        ans&=a[i];
    }
    cout<<ans;
    return;
}
void sol2(){
    int nmax = -1;
    for(int i=1;i<=n;i++){
        nmax = max(nmax,a[i]);
    }
    if(m==1)cout<<nmax;

}
void sol3(){
    int nmax=-1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i==j)continue;
            nmax = max(nmax,a[i]&a[j]);
        }
    }
    cout<<nmax;
    return ;
}
void sol4(){
    sort(a+1,a+n+1);
    int ans=a[n];
    for(int i=n-1;i>=n-m+1;i--)ans&=a[i];
    cout<<ans;
    return;
}
void sol5(){
    sort(a+1,a+n+1);
    int cnt1,cnt2,cnt3,cnt4;
    for(int i=1;i<=n;i++){
        if(a[i]==1)cnt1++;
        if(a[i]==2)cnt2++;
        if(a[i]==3)cnt3++;
        if(a[i]==4)cnt4++;
    }
    if(f==1){
        if(cnt4>=m)cout<<4;
        else if(cnt3>=m)cout<<3;
        else if(cnt3+cnt2>=m)cout<<2;
        else if(cnt3+cnt1>=m)cout<<1;
        else cout<<0;
    }
    else {
        int ans = a[n];
        for(int i=2;i<n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    return ;
}
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=4)f=0;
    }
    if(f==1||m==n-1)sol5();
    if(m==n)sol1();
    if(m==1)sol2();
    if(m==2)sol3();
    else sol4();
    return 0;
}
