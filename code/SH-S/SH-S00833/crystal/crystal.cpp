#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+10;
int a[N],b[N];
map<int,bool> mp;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(m==0){
        cout<<0;
    }
    int whatif=a[2]-a[1];
    bool f=1;
    for(int i=3;i<=n;i++){
        if(whatif!=(a[i]-a[i-1])){
            f=0;
            break;
        }
    }
    if(f){
            int g=a[2]-a[1],an=0;
        for(int i=1;m>0;m++){
            m-=(i*g);
            an++;
        }
        if(m<0){
            an--;
        }
        cout<<an;
    }
    int cnt=0x3f,rem=0;
    for(int i=1;i<=n;i++){
        int x=0;
        for(int j=1;j<=n;j++){
            if(j<i){x+=a[i]-a[j];}
            else if(j>i){x+=a[j]-a[i];}
        }
        if(cnt>x){
            cnt=x;
            rem=i;
        }
    }
    bool last=0;
    for(int i=1;i<=n;i++){
        b[i]=a[rem]-a[i];
        if(b[i]<0){
            b[i]*=(-1);
            last=1;
            mp[b[i]]=false;
        }
    }
    if(last){
        sort(b+1,b+1+n);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(m<=0){
                cout<<ans;
                return 0;
            }else{
                if(mp[b[i]]==false){
                    m-=b[i];
                    ans++;
                }else{
                    m-=(b[i]*i);
                    ans++;
                }
            }
        }
        return 0;
    }else{
        sort(b+1,b+1+n);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(m<=0){
                cout<<ans;
                return 0;
            }else{
                m-=(b[i]*i);
                ans++;
            }
        }
    }
    return 0;
}


//愿这题可以AC

