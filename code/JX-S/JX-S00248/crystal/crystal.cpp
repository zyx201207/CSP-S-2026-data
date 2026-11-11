#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N=5e5+10;
int n,m,sum=0;
int a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int cnt=-1;
    for(int i=1;i<=n;i++){
        int k=0;
        int l=0;
        for(int j=i;j>0;j--){
            k+=a[i]-a[j];
            if(k<=m){
                l++;
            }else{
                break;
            }
        }
        cnt=max(cnt,l);
    }
    cout<<cnt<<'\n';
    return 0;
}
