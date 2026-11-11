#include<bits/stdc++.h>
using namespace std;
#define int long long
long long c,t,n,d;
long long a[2000010],s[2000010];
long long di[310][310];
int ans=0;
int sum=0;
void dfs(int l,int r,int now,int s){

    if(s==di[l][r]+1){
        if(now==r){
            sum++;
        }
        return ;
    }
    for(int i=now+1;i<=r;i++){
        if(a[i]-a[now]>d){
            break;
        }
        //cout<<l<<" "<<r<<" "<<i<<" "<<s<<"\n";
        dfs(l,r,i,s+1);
    }
}
int check(int l,int r){
    sum=0;
    //cout<<l<<" "<<r<<"\n";
    dfs(l,r,l,1);
    //cout<<sum<<"\n";
    if(sum==2){
        return 1;
    }
    return 0;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            s[i]=a[i+1]-a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                int mad=1,la=i;
                for(int k=i+1;k<=j;k++){
                    if(__int128(a[k])-__int128(a[la])>__int128(mad*d)){
                        mad++;
                        la=k-1;
                    }
                    //cout<<k<<"  "<<la<<" "<<mad<<"\n";
                }
                if(__int128(a[j])-__int128(a[la])>__int128(d)){
                    mad++;
                }
                di[i][j]=mad;
                //cout<<i<<" "<<j<<" "<<mad<<"\n";
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
				//cout<<di[i][j]<<" ";
                if(di[i][j]<=1){
                    continue;
                }
                if(check(i,j)){
                    ans++;
                }
            }
            //cout<<"\n";
        }
        //cout<<"\n";
        cout<<ans<<"\n";
    }
    return 0;
}
/*
0 2
7 6
-10 -5 -1 1 3 5 9
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
