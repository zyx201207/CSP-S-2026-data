#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,m,num[N],maxa = -1;
bool b[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>num[i];
        maxa = max(maxa,num[i]);
    }
    if(m == 1){
        cout<<maxa<<endl;
        return 0;
    }
    if(m == n){
        int ans = num[0];
        for(int i=1;i<n;i++) ans &= num[i];
        cout<<ans<<endl;
        return 0;
    }
    for(int i=0;i<19;i++){
        if(pow(2,i) == n){
            cout<<0<<endl;
            return 0;
        }
    }
    return 0;
}
