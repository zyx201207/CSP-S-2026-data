#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    int h=1,t=n;
    long long ans=0;
    while(h<=t){
        if(c[h]!=c[t])
            ans+=min(a[h],a[t]);
        if(a[h]>a[t]){
                a[h]-=a[t];
                t--;
        }
        else if(a[h]<a[t]){
            a[t]-=a[h];
            h++;
        }
        else{
            h++;
            t--;
        }
    }
    cout<<ans;
    return 0;
}
