#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans,m,sum[35],maxlen,t,le,b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int l=a[i],len=0;
        while(l>0){
            if(l%2==1) sum[len+1]++;
            len++;
            l/=2;
        }
        maxlen=max(maxlen,len);
    }
    le=maxlen;
    while(sum[le]<m) le--;
    for(int i=1;i<=n;i++){
        int j=1,time=0;
        while(time<le){
            b[i]+=(a[i]%2)*j;
            j*=2;
            a[i]/=2;
            time++;
        }
    }
    sort(b+1,b+n+1);
    ans=b[n];
    for(int i=n-1;i>=n-m+1;i--){
        ans=ans&b[i];
    }
    cout<<ans;
	return 0;
}
