#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],could[200005],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
       cin>>a[i];
       could[i]=1;
    }
    for(int k=29;k>=0;k--){
        int sum=0;
        for(int i=1;i<=n;i++)
            if((a[i]&(1<<k)) && could[i]){
                sum++;
            }
        if(sum>=m)
        {
            //cout<<k<<"yes"<<endl;
            for(int i=1;i<=n;i++){
                if( ((a[i])&(1<<k)) ==0) could[i]=0;
            }
            ans+=(1<<k);
        }
        //for(int i=1;i<=n;i++) cout<<i<<":"<<could[i]<<"  ";
        //cout<<endl;
    }
    cout<<ans;
    return 0;
}
