#include<bits/stdc++.h>
using namespace std;
long long l,sum=0,ans=0,cnt=0,a[200005],m=0,n;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
    }
    while(sum<=l/2){
        m++;
        sum+=a[m];
    }
    m--;
    if(l%2==1){
        a[m+1]--;
        l--;
    }
//    cout<<l<<' '<<m<<endl;
    int j=n;
    for(int i=1;i<=m;i++){
        if(a[i]>=a[j]-cnt){
            a[i]-=a[j]-cnt;
            if(c[i]!=c[j])
                ans+=a[j]-cnt;
            while(a[i]>=a[j-1]){
                a[i]-=a[j-1];
                if(c[i]!=c[j-1])
                    ans+=a[j-1];
                j--;
            }
            cnt=a[i];
            if(c[j-1]!=c[i])
                ans+=a[i];
            j--;
        }
        else{
            cnt+=a[i];
            if(c[i]!=c[j])
                ans+=a[i];
        }
//        cout<<cnt<<' '<<j<<' '<<ans<<endl;
    }
    if(sum<l/2){
        m++;
        if(m!=j){
            long long x=l/2-sum;
            x-=(a[j]-cnt);
            if(c[m]!=c[j])
                ans+=a[j]-cnt;
            for(int i=m+1;i<=j-1;i++){
                if(c[m]!=c[i])
                    ans+=a[i];
            }
        }
    }
    cout<<ans;
    return 0;
}
