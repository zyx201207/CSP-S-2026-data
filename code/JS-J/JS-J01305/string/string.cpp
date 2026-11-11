#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    int i=1,cnt1=a[1],j=n,cnt2=a[n];long long ans=0;
    while(i<j){
        if(c[i]!=c[j])ans+=min(cnt1,cnt2);
        if(cnt1<cnt2){
            cnt2-=cnt1;
            i++;
            cnt1=a[i];
        }else if(cnt1>cnt2){
            cnt1-=cnt2;
            j--;
            cnt2=a[j];
        }else{
            i++;cnt1=a[i];
            j--;cnt2=a[j];
        }
    }//i==j->end
    cout<<ans;
    return 0;
}
