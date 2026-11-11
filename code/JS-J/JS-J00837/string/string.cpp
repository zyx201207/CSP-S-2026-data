#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],r,sum,ans,num;
char c[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    r=n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    int tmp=sum/2;
    bool flag=tmp%2;
    int sum2=0;
    while(sum2<=tmp)
      sum2+=a[++num];
    if(flag)
      a[num]--;
    sum2-=a[num--];
    for(int i=1;i<=num;i++){
        int tmp2=a[i];
        while(tmp2>=a[r]){
            if(c[r]!=c[i])
              ans+=a[r];
            tmp2-=a[r],r--;
        }
        if(tmp2){
            if(c[r]!=c[i])
              ans+=tmp2;
            a[r]-=tmp2;
        }
    }
    sum2=tmp-sum2;
    a[num+1]-=sum2;
    while(r>num+1){
        int tmp3=a[r];
        if(c[r]!=c[num+1])
          ans+=tmp3;
        r--;
    }
    cout<<ans;
    return 0;
}
