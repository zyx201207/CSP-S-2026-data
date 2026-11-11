#include <iostream>
using namespace std;
const int N = 2e5+10;
struct str{
    long long len = 0;
    char s;

}a[N];
long long sz[N];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long t_len = 0;
    for(long long i=1;i<=n;i++){
        cin>>a[i].len>>a[i].s;
        t_len += a[i].len;
    }
    long long l = 1;
    long long r = n;
    long long ans = 0;
    while(l<r){
        long long cha = a[l].len - a[r].len;
        if(a[l].s!=a[r].s){//diff
            if(cha == 0){
                ans += a[r].len;
                l++;
                r--;
            }
            else if(cha>0){
                ans += a[r].len;
                a[l].len -= a[r].len;
                r--;
            }
            else if(cha<0){
                ans+=a[l].len;
                a[r].len -= a[l].len;
                l++;
            }
        }
        else{//same
            if(cha == 0){
                l++;
                r--;
            }
            else if(cha>0){
                a[l].len -= a[r].len;
                r--;
            }
            else if(cha<0){
                a[r].len -= a[l].len;
                l++;
            }
        }

    }
    printf("%lld",ans);


    return 0;
}
