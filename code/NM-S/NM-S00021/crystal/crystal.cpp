#include<iostream>
#include<algorithm>
using namespace std;
const int N=5*1e5+10;
long long n,m,a[N],L=1,R,ans,ansmax;
bool check(long long x){
    long long cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=x){
            break;
        }
        else{
            cnt+=x-a[i];
        }
    }
    return cnt<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    R=n;
    sort(a+1,a+n+1);
    if(m>=(a[n]-a[1])*n){
        cout<<n;
        return 0;
    }
    while(L<=R){
        long long mid=(R-L)/2+L;
        if(check(a[mid])){
            L=mid+1;
            ans=mid;
        }else{
            R=mid-1;
        }
    }
    cout<<ans;
    //ben lai xiang zhe yong tan xin,er fen da an ju ran neng guo??
    //14:58 yang li 4 mei guo,ka le
    //tan xin bu hui xie, er fen da an neng pian 30pts ma(((
    return 0;
}
