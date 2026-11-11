#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,cnt=1;
    cin>>n>>m;
    int x[10005];
    for(int i=1;i<=n;i++){
        cin>>x[i];
        if(x[i]==12) cnt++;
    }
    if(cnt>0){
        cout<<12;
    }

}
