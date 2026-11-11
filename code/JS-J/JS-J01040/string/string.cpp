#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
const ll MAXN=2*1e5+3;

int num[MAXN];
char a[MAXN];
int mid,ans,j;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    cin>>n;
    ll len=1;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        char w;
        cin>>w;
        for(int j=len;j<=num[i];j++){
            a[j]=w;
        }
        len+=num[i];
    }
    len-=1;
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n==2){
        if(a[1]==a[len]){
            cout<<0;
            return 0;
        }else{
            int qw=min(num[1],num[2]);
            cout<<qw;
            return 0;
        }
    }


        mid=len/2+1;


    for(int i=mid;i<=len;i++){
        if(len%2==1){
            mid+=1;
        }
        ans=0;

        for(int j=mid-1;j>=1;j--){
            if(a[i]!=a[j]){
            ans+=1;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}
