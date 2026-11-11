#include<bits/stdc++.h>
using namespace std;
#define int long long

char a[200005]{};
long long b[200005]{};
long long sum=0,mid,now1=1,now2,ans=0;

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>b[i]>>a[i];
        sum+=b[i];
    }
    mid=sum/2+1;
    now2=n;
    int i=1;
    while (i<mid){
        if(a[now1]==a[now2]){
            i+=min(b[now1],b[now2]);
            if(b[now1]>b[now2]){
                b[now1]-=b[now2];
                now2--;

            }
            else if(b[now1]==b[now2]){
                now1++;
                now2--;
            }
            else {
                b[now2]-=b[now1];
                now1++;
            }
        }
        else{
            ans+=min(b[now1],b[now2]);
            i+=min(b[now1],b[now2]);
            if(b[now1]>b[now2]){
                b[now1]-=b[now2];
                now2--;
            }
            else if(b[now1]==b[now2]){
                now1++;
                now2--;
            }
            else {
                b[now2]-=b[now1];
                now1++;
            }
        }
    }
    cout<<ans;
    return 0;
}
