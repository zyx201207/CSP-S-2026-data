#include<bits/stdc++.h>
using namespace std;
int n;
char a[200005],b[200005],ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        int cnt = b[1];
        if(b[i]==b[1]){
            ans+=0;
        }
        else{
            ans++;
        }
    }
    if(n==1){
        cout<<0;
    }
    else if(ans==0){
        cout<<0;
    }
    return 0;
}
