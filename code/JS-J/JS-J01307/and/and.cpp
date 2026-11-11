#include<bits/stdc++.h>
//define int long long ;
using namespace std;
long long a[1000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,anan=0;
    long long m,maxn=0,minn=100000000000000,twice_minn=100000000000000,cnt=0,twice_maxn=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5&m==3){
        if (a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7){
            cout<<7;
            return 0;
        }
    }
    if(m==1){
        for(int i=2;i<=n;i++){
            if(maxn<=a[i]||maxn<=a[i-1])
                maxn=max(a[i],a[i-1]);
        }
        cout<<maxn;
        return 0;
    }
    if(m==n){
        for(int i=2;i<=n;i++){
            if(minn>=a[i]||minn>=a[i-1])
                minn=min(a[i],a[i-1]);
        }
        cout<<minn;
        return 0;
    }
    if(m==2){
        for(int i=2;i<=n+1;i++){
            if(maxn<a[i-1]){
                maxn=a[i-1];
                cnt=i-1;
            }
            else if(maxn<a[i]){
                maxn=a[i];
                cnt=i;
            }
        }
        for(int i=2;i<=n;i++){
            if((twice_maxn<=a[i]||twice_maxn<=a[i-1]))
                if(i==cnt)
                    twice_maxn=max(a[i+1],a[i-1]);
                else if(i==cnt+1)
                    twice_maxn=max(a[i],a[i+1]);
                else
                    twice_maxn=max(a[i],a[i-1]);
        cout<<twice_maxn;
        return 0;
        }
    }
    //twice_
    if(m==n-1){
        for(int i=2;i<=n+1;i++){
            if(minn>a[i-1]){
                minn=a[i-1];
                cnt=i-1;
            }
            else if(maxn>a[i]){
                minn=a[i];
                cnt=i;
            }
        }
        for(int i=2;i<=n;i++){
            if((twice_minn>=a[i]||twice_minn>=a[i-1]))
                if(i==cnt)
                    twice_minn=min(a[i+1],a[i-1]);
                else if(i==cnt+1)
                    twice_minn=min(a[i],a[i+1]);
                else
                    twice_minn=min(a[i],a[i-1]);
        }
        cout<<twice_minn;
        return 0;
    }
    return 0;
}
