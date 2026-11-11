#include <bits/stdc++.h>
#define LL long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n,m;
int a[1000005];
int zh=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    IOS;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(!m){
        cout<<1;
        return 0;
    }
    int c=abs(a[1]-a[0]);
    for(int i=1;i<n;i++){
        if(m>=i*c){
            m-=i;
            zh++;
        }else break;
    }
    cout<<zh;


    return 0;
}
