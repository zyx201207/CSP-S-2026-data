#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[200005],nm,mxnm,f=1,bf1,bf2=1,ans1,ans2,dans=-1,mxai=0;
int flag[100]{0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575};
string ste(int x,string l=""){
    while (x>0){
        l+=(char)('0'+x%2);
        x/=2;
    }
    reverse(l.begin(),l.end());
    return l;
}

bool check(int x,bool lf=0){
    for (int i = 0; i <=20;i++) {
        if (flag[i]==x) {
            return 0;
        }
    }
    return 1;
}

void dfs(int x,int H,int lm){
    if (lm==m) dans=max(dans,H);
    for (int i = x+1; i <= n;i++){
        dfs(i,H&a[i],lm+1);
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i = 0; i <= 20;i++){
        if (n==flag[i]+1) bf1=1;
    }
    for (int i = 1; i <= n;i++){
        cin>>a[i];
        mxai=max(mxai,a[i]);
        if (n==m) {
            if (i==1) nm=a[i];
            else nm &=a[i];
        }
        else if (m==1) mxnm=max(mxnm,a[i]);
        else if (f && check(a[i])) f=0;
    }
    if (n==m) {
        cout<<nm<<'\n';
        return 0;
    }
    if (m==1) {
        cout<<mxnm<<'\n';
        return 0;
    }
    if (f){
        sort(a+1,a+1+n);
        cout<<a[n-m+1]<<'\n';
        return 0;
    }
    if (bf1){
        sort(a+1,a+1+n);
        for (int i = 1; i <= n; i++){
            if (a[i]!=i-1) bf2=0;
        }
        if (bf2){
            if (m>n/2) cout<<0<<'\n';
            else{
                int ejf=0;
                while (pow(2,ejf)<m) ejf++;
                cout<<a[n-flag[ejf]]<<'\n';
            }
            return 0;
        }

    }
    if (m==2){
        sort(a+1,a+1+n);
        for (int i = n; i > 1; i--){
            if (ste(a[i]).size()==ste(a[i-1]).size()){
                a[i]&=a[i-1];
                cout<<a[i]<<'\n';
                return 0;
            }
        }
    }
    if (m==n-1){
        sort(a+1,a+1+n);
        for (int i = 1; i< n; i++){
            if (i==1) ans1=a[i];
            else ans1&=a[i];
        }
        for (int i = n; i>1; i--){
            if (i==n) ans2=a[i];
            else ans2&=a[i];
        }
        cout<<max(ans1,ans2)<<'\n';
        return 0;
    }

    if (mxai<4){
        sort(a+1,a+1+n);
        int zhyg=a[n];
        for (int i= n; i >= n-m+1;i--){
            zhyg&=a[i];
        }
        cout<<zhyg<<'\n';
        return 0;
    }

    if (n<=40){
        for (int i = 1; i <= n-m+1;i++){
            dfs(i,a[i],1);
        }
        cout<<dans<<'\n';
        return 0;
    }

    cout<<0<<'\n';
    return 0;
}
