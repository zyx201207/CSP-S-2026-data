#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    long long ans=0;
    int L=1,R=n;
    while(L<R){
        if(c[L]!=c[R]){
            if(a[L]>a[R]){
                ans+=a[R];
                a[L]-=a[R];
                R--;
            }else if(a[L]<a[R]){
                ans+=a[L];
                a[R]-=a[L];
                L++;
            }else{
                ans+=a[L];
                L++;
                R--;
            }
        }else{
            if(a[L]>a[R]){
                a[L]-=a[R];
                R--;
            }else if(a[L]<a[R]){
                a[R]-=a[L];
                L++;
            }else{
                L++;
                R--;
            }
        }
    }
    cout<<ans;
    return 0;
}
