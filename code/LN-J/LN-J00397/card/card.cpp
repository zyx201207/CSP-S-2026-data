#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m;
int a[N];
int cnt[M];
int b[N];
int flag=0;
int main(){
     freopen("card.in","r",stdin);
     freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]) flag=1;
    }
    if(flag==0){
        for(int i=1;i<=m;i++){
            cnt[b[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<cnt[i]<<' ';
        }
    }
    else if(m==1) {
        cout<<m;
    }
    return 0;
}
