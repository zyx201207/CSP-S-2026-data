#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;
ll a[N],d[N];
int l=1,num=0,mx=-1;
unsigned long long sum,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        d[i]=a[i]-a[i-1];
        sum+=(++num)*d[i];
        while(sum>m){
            num--;
            sum=sum-(a[i]-a[l++]);
        }
        mx=max(mx,num);
    }
    cout<<mx+1<<'\n';
    return 0;
}
//coded by LF Jyouhan
// Could you hear the alarming of "echoing"?
