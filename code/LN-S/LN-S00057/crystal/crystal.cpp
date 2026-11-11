#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long cnt[100000000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long a[n+10];
    long long q1=-100000000000,q2=100000000000;
    long long w=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        q1=max(q1,a[i]);
        q2=min(q2,a[i]);
        if(a[i]==a[i-1]+1)w++;
    }
    long long s=0,b=q2;
    for(int i=q2;i<=q1;i++){
        if(cnt[i]>=s&&i>b){
            s=cnt[i];
            b=i;
        }
    }
    if(w==n-1){
        int ans=0;
        for(int i=1;i<=b;i++){
            if(m<=ans+i&&i<n){
                cout<<i+s;
                return 0;
            }
            else if(i>=n){
                cout<<n;
            }
            else{
                ans+=i;
            }
        }
    }
    else if(s==1){
        int dd=0;
        int cnt1=0;
        b=(n+1)/2;
        for(int i=1;i<=(n+1)/2;i++){
            if(m>=b-a[i]){cnt1++;m-=b-a[i];}
        }
        cout<<cnt1;
        return 0;
    }
    else{
         int cnt1=0;
         int dd=0;
         for(int i=1;i<=n;i++){
            if(a[i]==b){dd=i;break;}
         }
         for(int i=dd-1;i>=1;i--){
            if(m>=b-a[i]){cnt1++;m-=b-a[i];}
         }
         cout<<cnt1+s;
    }
    fclose(stdin);
    fclose(stdout);
}
