#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long c[500005];
long long cnt=1;
int n,m;
void fy(int id,int r){

    id++;
    c[id]=0;
    int x=a[id];
    for(int i=id+1;i<=r;i++){
        c[i]=c[i-1]+(x-a[i]);
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    int x=a[1];
    c[1]=0;
    int id=1;
    int t=n;
    for(int i=2;i<=n;i++){
        c[i]=c[i-1]+(x-a[i]);
        m--;
        cnt++;
        if(c[i]>=m&&i<=(t+1)/2){
            fy(id,i);
            id++;
            x=a[id];
            cnt--;
            t--;
            m++;
        }
        else if(i>(n+1)/2&&c[i]>=m){
            cout<<cnt;
            break;
        }
        else if(i==n&&c[i]<m){
            cout<<cnt;
            break;
        }
    }
    return 0;
}
