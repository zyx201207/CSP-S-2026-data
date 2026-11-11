#include<bits/stdc++.h>
using namespace std;
int n;
long long maxp=0;
long long m;
long long a[500005];
int spe[500005];
void substack12345(){
    int maxx=0;
    long long x=maxp;
    int l=
    for(int ave=-x;ave<=x;ave++){

        long long m0=m;
        for(int i=1;i<=n;i++){
            spe[i]=0;
        }
        for(int i=1;i<=n;i++){
            spe[i]=abs(a[i]-ave);
        }
        sort(spe+1,spe+n+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(m0>=spe[i]){
                ans++;
                m0-=spe[i];
            }
            else{
                break;
            }
        }
        maxx=max(maxx,ans);
    }
    cout<<maxx;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxp=max(maxp,abs(a[i]));
    }
    substack12345();
}
