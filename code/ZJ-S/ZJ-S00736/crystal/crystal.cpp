#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
const unsigned long long M=1e18;
unsigned long long m;
int n,a[N],cnt[N],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    if(m==M){
        cout<<n;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) cnt[i]=a[i]-a[i-1];
    if(n<=20){
        for(int ii=1;ii<=n;ii++){
            int s1=0,s2=0;
            for(int i=ii;i>=2;i--){
                s1+=cnt[i];
                for(int j=ii+1;j<=n;j++){
                    s2+=cnt[j];
                    if(s1+s2<=m){
                        ans=max(ans,j-i+2);
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(n<=10000){//sfdsdssaadsadasdasdf
        deque<int> mp[n+10];
        for(int ii=1;ii<=n;ii++){
            int s1=0,s2=0;
            for(int i=ii;i>=2;i--){
                mp[ii].push_back(s1+cnt[i]);
                s1+=cnt[i];
            }
            for(int i=ii+1;ii<=n;ii++){
                mp[ii].push_back(s2+cnt[i]);
                s2+=cnt[i];
            }
        }
        for(int i=1;i<=n;i++) sort(mp[i].begin(),mp[i].end());
        for(int i=1;i<=n;i++){
            int u=m;
            for(int j=0;j<mp[i].size();j++){
                if(mp[i][j]>u){
                    ans=max(ans,j);
                    break;
                }
                u-=mp[i][j];
            }
        }
        cout<<ans;
        return 0;
    }
    if(m>1e8){
        long long u=a[2]-a[1];
        int g=m/u;
        int op=g/2;/*
        if(g==0){cout<<1;return 0;}if(g==1){cout<<2;return 0;}if(g==2){cout<<3;return 0;}
        if(g==3){cout<<3;return 0;}if(g==4){cout<<4;return 0;}if(g==5){cout<<4;return 0;}
        if(g==6){cout<<5;return 0;}if(g==7){cout<<5;return 0;}//*/
        long long l=1,r=n,mid,pos;
        while(l<=r){
            mid=(l+r)>>1;
            if(mid*(mid+1)<=op){
                pos=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        if(g-pos*2>=pos+1) cout<<min(n,int(2+pos*2));
        else cout<<min(n,int(1+pos*2));
        return 0;
    }
    return 0;
}
