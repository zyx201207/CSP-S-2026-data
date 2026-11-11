#include<bits/stdc++.h>
using namespace std;
int n,m;
bool a[200005][32];
int s[32]={0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        for(int j=0;x>0;j++){
            a[i][j]=x%2;
            s[j]++;
            x=x>>1;
        }
    }
    int ans=0;
    int b=-1;
    int tim=32;
    for(int i=31;i>=0;i--){
        if(s[i]>=m){
            b=i;
            ans=1<<b;
            break;
        }
    }
    if(b==-1){
        cout<<0;
        return 0;
    }
    bool ab[200005]={0};
    while(tim--&&tim>=0){
        int a2[200005]={0};
        int la2=0;
        int s2[32]={0};
        for(int i=0;i<n;i++){
            if(a[i][b]==1&&ab[i]==0)a2[la2++]=i;
        }
        for(int i=0;i<n;i++){
            ab[i]=1;
        }
        for(int i=0;i<la2;i++){
            ab[a2[i]]=0;
        }
        int bj2=0;
        for(int i=0;i<n;i++){
            if(i==a2[bj2]){
                for(int j=b-1;j>=0;j--){
                    s2[j]+=a[i][j];
                }
                bj2++;
            }
        }
        if(s[b]==m){
            for(int i=b-1;i>=0;i--){
                if(s2[i]==m)ans+=1<<i;
            }
            cout<<ans;
            return 0;
        }
        int tur=0;
        for(int i=b-1;i>=0;i--){
            if(s2[i]>=m){
                b=i;
                tur=1;
                ans+=1<<i;
                break;
            }
        }
        if(tur==0){
            cout<<ans;
            return 0;
        }
    }
    return 0;
}
