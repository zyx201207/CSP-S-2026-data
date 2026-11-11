#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ans,a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n;
    while(1){
        if(a[i]==0)i++;
        if(a[j]==0)j--;
        if(i>=j){
            cout<<ans<<'\n';
            return 0;
        }
        if(a[i]<=a[j]){
            if(c[i]!=c[j])ans+=a[i];
            a[j]-=a[i];
            i++;
        }
        else{
            if(c[i]!=c[j])ans+=a[j];
            a[i]-=a[j];
            j--;
        }
    }
    return 0;
}
