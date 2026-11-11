#include<bits/stdc++.h>
using namespace std;
const int N=2e5+4;
int n,m;
struct node{
    int x;
    string s="";
    bool ok=false;
}a[N];
void work(int i){
    int t=a[i].x;
    while(t){
        a[i].s+=(t%2+'0');
        t/=2;
    }
    reverse(a[i].s.begin(),a[i].s.end());
}
void f(int mxl){
    int cnt=0;
    while(--mxl>=0){
        cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i].s.size()<mxl+1)continue;
            if(a[i].ok && a[i].s[mxl]=='1'){
                a[i].ok=true;
                cnt++;
            }
            else{
                a[i].ok=false;

            }
        }
        if(cnt>=m) break;
    }
    int t=2147483647;
    if(cnt==m){
        for(int i=1;i<=n;i++){
            if(a[i].ok){
                t=t&a[i].x;
            }
        }cout<<1;
        cout<<t;
        return;
    }
    if(cnt>m){
        f(mxl-1);
    }

    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int mxl;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        work(i);
        int t=a[i].s.size();
        mxl=max(mxl,t);
    }
    int cnt=0;
    while(--mxl>=0){
        cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i].s.size()<mxl+1)continue;
            if(a[i].s[mxl]=='1'){
                a[i].ok=true;
                cnt++;
            }
        }
        if(cnt>=m) break;
    }
    int t=2147483647;
    if(cnt==m){
        for(int i=1;i<=n;i++){
            if(a[i].ok){
                t=t&a[i].x;
            }
        }
        cout<<t;
        return 0;
    }
    if(cnt>m){
        f(mxl-1);
    }


    return 0;
}

