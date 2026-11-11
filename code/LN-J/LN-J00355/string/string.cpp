#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];

int main(){
    ios::sync_with_stdio(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(c[i]==c[i-1]){
            a[i-1]+=a[i];
            n--,i--;
        }
    }

    long long i=1,j=n,ans=0;
    while(i<j){
        if(c[i]==c[j]){
            if(a[i]==a[j])i++,j--;
            else if(a[i]>a[j])a[i]-=a[j--];
            else a[j]-=a[i++];
        }
        else{
            if(a[i]==a[j])ans+=a[i],i++,j--;
            else if(a[i]>a[j])ans+=a[j],a[i]-=a[j--];
            else ans+=a[i],a[j]-=a[i++];
        }
    }
    cout<<ans<<endl;
    return 0;
}
