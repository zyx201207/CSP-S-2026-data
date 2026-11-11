
#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int b[n-1];
    int p[n+10],sum=m,opo=0;
    memset(p,0,sizeof(p));
    int ans=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<ans+1;j++){
            if(sum>=abs(a[j]-a[i])){sum-= abs(a[j]-a[i]);
            p[ans]+=1;}
            else{
                opo++;
                break;
            }
        }
        sum=m;
        ans++;
    }
    if(opo==n-1){
        cout<<1;
        return 0;
    }
    sort(p,p+n-1,cmp);
    cout<<p[n-1-1]+1;
    return 0;
}
//KeyNG!!!
