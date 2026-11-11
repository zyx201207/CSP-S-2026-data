#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll m,a[N],p[N];
int n,cnt=1;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    p[1]=0;
    cin>>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        p[i]=p[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i-cnt;j++){
            if(p[i]-p[j]>m){
                break;
            }else{
                cnt=max(cnt,i-j+1);
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
//CCF is my baba.
