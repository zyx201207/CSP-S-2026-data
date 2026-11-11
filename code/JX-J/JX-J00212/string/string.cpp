#include<bits/stdc++.h>
using namespace std;
long long a[200005];char c[200005];long long b[200005];
int n;string s;long long cnt=0;long long maxn=0;long long jh=0;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;b[0]=-1;
for(int i=1;i<=n;i++){
    cin>>a[i]>>c[i];
    for(int j=1;j<=a[i];j++){
        s+=c[i];
    }
    maxn=max(a[i],maxn);
    b[i]=a[i]+b[i-1];
    jh+=a[i];
}
if(n==1){
    cout<<"0"<<endl;
    return 0;
}
else{
    if((long long)maxn*n<=1e8){
        int u=s.size();
    for(int i=0;i<s.size()/2+1;i++){
        if(s[i]!=s[u-i-1]){
            cnt++;
        }
    }
    cout<<cnt<<endl;return 0;
    }
    else{
      for(int i=1;i<=n;i++){
            for(int j=n;j>n/2-1;j--){
                    if(j<=i)break;
                  if(jh-b[i]-1>=b[j-1]&&b[j]>jh-b[i]-1){
                    long long k=jh-b[i]-1;
                    long long y=jh-a[i-1]-2;
                    if(a[i]!=a[j-1]){
                        cnt+=min(y,b[j]-1)-max(k,b[j-1]);
                    }
                  }
            }

      }
    }
}
return 0;
}
