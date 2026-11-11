#include<bits/stdc++.h>
using namespace std;
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
const maxn=1000010;
int a[maxn];
int main(){
    int n,m;
    cin>>n' '>>m;
    for(int i=1;i<=n ;i++){
        for(int j=1;j<=m;j++){
            int cnt;
            if(a[j+1]==k){
                if(a[i]!=k){
                    a[i]+=k;
                    cnt++;
                }
                else(){
                    break;
                }
                cout<<cnt;
            }
        }
    }
    return 0;
}
