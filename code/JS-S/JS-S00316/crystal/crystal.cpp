#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int MAXN=5e5+5;
ll a[MAXN];
ll pre[MAXN];
int n,k;
void prepr(){
    pre[1]=a[1];
    for(int i=2;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }

}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    prepr();
    int mx=0;
    int l=1,r=2;
    while(l>0&&r<=n){
        if(pre[r-1]-pre[l-1]+k>=(r-l)*a[r]){
                mx=max(mx,r-l+1);
                r++;
            }else{
                l++;
            }
    }
    cout<<mx<<endl;
    return 0;
}
