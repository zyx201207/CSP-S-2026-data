#include<bits/stdc++.h>
using namespace std;
vector<int> num(200005);
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxnum = -1;
    for(int i=1 ;i<=n;i++){cin>>num[i];maxnum = max(maxnum,num[i]);}
    int fgh = num[1] | num[2];
    for(int i=3 ;i<=n;i++){fgh = fgh| num[i];}
    if(m == 1){cout<<maxnum;return 0;}
    if(m == n){cout<<fgh;return 0;}
    int jkl = num[1] | num[2];
    for(int i=1 ;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            jkl = max(jkl,num[i] | num[j]);
        }
    }
    if(m == 2){cout<<jkl;return 0;}
    return 0;
}
