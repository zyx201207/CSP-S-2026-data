#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,n,a[1010110],use[1010110],ans,t[40],f[1010110];
vector<int>bit[40];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=1;
    }
    int i=31,k=1;
    while(i>=0){int t=0;
        for(int j=1;j<=n;j++){
            if((k||f[j])&&(a[j]>>i)&1){
                f[j]=1;t++;
                //cout<<"now "<<a[j]<<" ";
            }else f[j]=0;
        }
        //cout<<endl;
        if(t>=m){
            k=0;ans+=1<<i;
            //cout<<"got"<<ans<<" "<<i<<endl;
        }i--;
    }
    cout<<ans;
    return 0;
}/*
11111













inclusteam
dcciyiyz
tdchuidiervsxt
2026/10/31 8:30:00
*/
