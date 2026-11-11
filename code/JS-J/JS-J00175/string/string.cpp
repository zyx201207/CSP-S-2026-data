#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    int i=1,j=n,ni=a[1],nj=a[n];
    while(i!=j){
        if(ni>=nj){
            if(c[i]!=c[j])ans+=nj;
            ni-=nj;
            j--;
            nj=a[j];
        }else{
            if(c[i]!=c[j])ans+=ni;
            nj-=ni;
            i++;
            ni=a[i];
        }
    }
    cout<<ans;
    return 0;
}
