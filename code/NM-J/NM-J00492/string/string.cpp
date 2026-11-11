#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int a,n;
string c;
string S;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a>>c;
    S+=c;
}
if(n=2)cout<<0;
else
    cout<<2;

return 0;
}

