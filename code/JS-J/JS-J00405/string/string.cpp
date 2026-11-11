#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int n,mid=0,sum=0,ls[N],ans=0,ls2[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ls[i];
        sum+=ls[i];
        string x;
        cin>>x;
        ls2[i]=x[0]-'a';
    }
    if(sum%2==1){
        mid=(int)sum/2+1;
        int gol_l=1,gol_r=n,fgl=ls[1],fgr=ls[n];
        for(int i=1;i<=mid-1;i++){
            int minn=min((fgl-i),(fgr-i));
            if(ls2[gol_l]!=ls2[gol_r]){
                ans+=minn+1;
            }
            i+=minn;
            if(i==fgl){gol_l++;fgl+=ls[gol_l];}
            if(i==fgr){gol_r--;fgr+=ls[gol_r];}
        }
    }
    else{
        mid=(int)sum/2;
        int gol_l=1,gol_r=n,fgl=ls[1],fgr=ls[n];
        for(int i=1;i<=mid;i++){
            int minn=min((fgl-i),(fgr-i));
            if(ls2[gol_l]!=ls2[gol_r]){
                ans+=minn+1;
            }
            i+=minn;
            if(i==fgl){gol_l++;fgl+=ls[gol_l];}
            if(i==fgr){gol_r--;fgr+=ls[gol_r];}
        }
    }
    cout<<ans<<endl;
    return 0;
}