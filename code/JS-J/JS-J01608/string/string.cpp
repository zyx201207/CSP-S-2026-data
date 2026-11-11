#include <iostream>
#include <cstdio>
using namespace std;
long long n,a[200005],cnt;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++)cin>>a[i]>>c[i];
    long long i=1,ri=a[1],j=n,rj=a[n];
    while(i<j){
        if(c[i]==c[j]){
            if(ri==rj){
                i++;
                j--;
                ri=a[i];
                rj=a[j];
            }
            else if(ri>rj){
                j--;
                ri-=rj;
                rj=a[j];
            }
            else if(ri<rj){
                i++;
                rj-=ri;
                ri=a[i];
            }
        }
        else{
            if(ri==rj){
                i++;
                j--;
                cnt+=rj;
                ri=a[i];
                rj=a[j];
            }
            else if(ri>rj){
                cnt+=rj;
                j--;
                ri-=rj;
                rj=a[j];
            }
            else if(ri<rj){
                cnt+=ri;
                i++;
                rj-=ri;
                ri=a[i];
            }
        }
    }
    cout<<cnt;
    return 0;
}
