#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,fa=1,fb=1,la[N];
long long m,a[N],ans=0,d=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>a[1];
    if(a[1]!=1)fa=0;
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)fa=0;
    }
    sort(a+1,a+n+1);
    if(n==1){
        cout<<1;
        return 0;
    }
    else if(n==2){
        cout<<(a[2]-a[1]<=m?2:1);
        return 0;
    }
    d=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=d)fb=0;
    }
    if(fa){
        int i=1;
        while(m>0&&i<n){
            if(m>=a[i]){
                m-=a[i];
                i++;
            }
            else{
                m=0;
            }
        }
        cout<<i;
    }
    else if(fb){
        int i=1;
        while(m>0&&i<n){
            if(m>=d*i){
                m-=d*i;
                i++;
            }
            else{
                m=0;
            }
        }
        cout<<i;
    }
    else{
        int sum=1;
        la[0]=0;
        la[n]=n;
        for(int i=n-1;i>=1;i--){
            if(a[i]==a[i+1]){
                la[i]=la[i+1];
            }
            else{
                la[i]=i;
                sum++;
            }
        }
        int j=0;
        for(int i=1;i<=sum;i++){
            j=la[j]+1;
            long long cnt=la[j]-j+1,mm=m;
            int k=j;
            while(mm>0&&k<n){
                if(mm>=(a[la[k]+1]-a[k])*(la[k]-k+1)){
                    mm-=(a[la[k]+1]-a[k])*(la[k]-k+1);
                    k=la[k]+1;
                    cnt+=la[k]-k+1;
                }
                else{
                    long long dd=a[la[k]+1]-a[k];
                    k=la[k]+1;
                    cnt=max(cnt,la[k]-k+1+mm/dd);
                    mm=0;
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
    }
    return 0;
}
