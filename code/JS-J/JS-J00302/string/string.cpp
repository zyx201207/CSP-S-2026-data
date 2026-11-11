#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
char s[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,cnt=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        cin>>s[i];
    }
    for(long long L=1,R=n;L<R;){
        if(s[L]==s[R]){
            if(a[L]>a[R]){
                a[L]-=a[R];
                R--;

            }
            else if(a[L]<a[R]){
                a[R]-=a[L];
                L++;
            }
            else if(a[L]==a[R]){
                R--;
                L++;
            }
        }
        else {
            if(a[L]>a[R]){
                cnt+=a[R];
                a[L]-=a[R];
                R--;

            }
            else if(a[L]<a[R]){
                cnt+=a[L];
                a[R]-=a[L];
                L++;
            }
            else if(a[L]==a[R]){
                cnt+=a[L];
                R--;
                L++;
            }

        }
    }
    cout<<cnt;
    return 0;
}
