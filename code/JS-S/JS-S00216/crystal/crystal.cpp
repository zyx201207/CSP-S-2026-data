#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    unsigned long long n,m;
    cin>>n>>m;
    long long k1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    bool A=true;
    bool B=true;
    k1=a[2]-a[1];
    if(k1!=1){
        A=false;
    }
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=k1){
            A=false;
            B=false;
            break;
        }
    }
    if(A==true){
        if(m<1){
            cout<<1;
            return 0;
        }
        unsigned long long cnt=2;
        for(int i=1;i<=m;i++){
            if(i<=m){
                m-=i;
                cnt++;
            }
            cout<<min(n,cnt);
            return 0;
        }
    }
    if(B==true){
        if(m<k1){
            cout<<1;
            return 0;
        }
        unsigned long long cnt=2;
        for(int i=1;i<=m;i++){
            if(i*k1<=m){
                m-=i*k1;
                cnt++;
            }
            cout<<min(n,cnt);
            return 0;
        }
    }
    unsigned long long maxn=0,cnt=1;
    for(unsigned long long i=1;i<=n;i++){
        unsigned long long l=i-1,r=i+1,k=m;
        unsigned long long lost1=0;
        unsigned long long lost2=0;
        while(l>=1&&r<=n){
            lost1=a[i]-a[l];
            lost2=a[r]-a[i];
            if(k<lost1&&k<lost2){
                break;
            }
            if(lost1<=lost2&&k>=lost1){
                k-=lost1;
                l--;
                cnt++;
            }else if(lost1>lost2&&k>=lost2){
                k-=lost2;
                r++;
                cnt++;
            }
        }
        if(k>0&&l>=1){
            for(long long j=l;j>=1;j--){
                lost1=a[i]-a[j];
                if(k>=lost1){
                    k-=lost1;
                    cnt++;
                }else{
                    break;
                }
            }

        }
        else if(k>0&&r<=n){
            for(long long j=r;j<=n;j++){
                lost2=a[j]-a[i];
                if(k>=lost2){
                    k-=lost2;
                    cnt++;
                }else{
                    break;
                }
            }
        }
        maxn=max(cnt,maxn);
        cnt=1;
        k=m;

    }
    cout<<min(n,maxn);
    return 0;
}
