#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    int a[100005];
    for (int i=1;i>=n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }
    for(int i=1;i<=n;i++){
        a[i]+=1;
        m-=1;
        while(a[i]==a[i-1]==a[i+1]==a[i-2]){
            if(a[i]<a[i+1]){
                a[i]+=1;
                m-=1;
            }if(a[i-1]<a[i]){
                a[i-1]+=1;
                m-=1;
            }if(a[i]<a[i-2]){
                a[i-2]+=1;
                m-=1;
            }
        }
    }
    int answer=0;
    for(int i=2;i<=n;i++){
        if(a[i]==a[2]){
            answer+=1;
        }
    }
    cout<<answer<<"\n";
    return 0;
}
