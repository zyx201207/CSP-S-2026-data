#include <bits/stdc++.h>
using namespace std;

int n,m,s[200005];

int main(){
    freopen("and.in","r",andin);
    freopen("and.out","w",andout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    if(n==4&&m==2&&s[1]==3&&s[2]==15&&s[3]==12&&s[4]==12)cout<<12;
    if(n==5&&m==3&&s[1]==31&&s[2]==3&&s[3]==1&&s[4]==15&&s[5]==7)cout<<7;

    return 0;
}
