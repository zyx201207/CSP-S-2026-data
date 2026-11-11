#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(int)a;i<(int)b;i++)

using namespace std;
long long n,m,sum[500005],cnt=1,f[5005][5005],casea=1,g=0;
vector<long long> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);


    cin>>n>>m;
    For(i,0,n){
        long long x;
        cin>>x;
        v.emplace_back(x);
    }
    sort(v.begin(),v.end());
    g=v[1]-v[0];
    For(i,2,n){
        if(v[i]-v[i-1]!=g){
            casea=0;
        }
    }
    if(casea==1){
        long long sumg=0,gc=1;
        while(sumg+g*gc<=m){
            sumg+=g*gc;
            gc++;
        }
        cout<<gc;
        return 0;
    }
    sum[0]=v[0];
    For(i,1,n){
        sum[i]=sum[i-1]+v[i];
    }
    For(len,2,n+1){
        long long minx=1e18;
        For(i,0,n+1-len){
            int j=i+len-1;
            if(v[j]*(j-i)-sum[j-1]+sum[i-1]<minx){
                if(i-1>0) minx=v[j]*(j-i)-sum[j-1]+sum[i-1];
                else minx=v[j]*(j-i)-sum[j-1];
            }
        }
        if(minx<=m){
            cnt=len;
        }
        else{
            break;
        }
    }
    cout<<cnt;
    return 0;
}





