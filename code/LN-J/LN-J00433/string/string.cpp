#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],total=0,ans=0;
char c[N];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        total+=a[i];
    }
    long long i=1,j=n,cnt=0;
    while(i<=j&&cnt<total/2){
        if(i==j){
            break;
        }else{
            if(c[i]==c[j]){
                long long q=min(a[i],a[j]);
                cnt+=q;
                a[i]-=q;
                a[j]-=q;
                if(a[i]==0)i++;
                if(a[j]==0)j--;
            }else if(c[i]!=c[j]){
                long long q=min(a[i],a[j]);
                ans+=q;
                cnt+=q;
                a[i]-=q;
                a[j]-=q;
                if(a[i]==0)i++;
                if(a[j]==0)j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
