#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long cry[100005],cha[100005];
int cmp(int a,int b){
    if(a>b)return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cry[i];
    }
    sort(cry+1,cry+n+1,cmp);
    long long ma=-1;
    for(long i=1;i<n;i++){
        for(long j=i+1;j<=n;j++){
            cha[j]=cry[i]-cry[j];
        }
        long long s=m;
        long long cnt=0;
        for(long j=i+1;j<=n;j++){
            s-=cha[j];
            if(s<0){
                break;
            }
            else{
                cnt++;
            }
        }
        if(cnt>0){
            cnt++;
        }
        ma=max(ma,cnt);
    }
    cout<<ma<<'\n';
    return 0;
}
