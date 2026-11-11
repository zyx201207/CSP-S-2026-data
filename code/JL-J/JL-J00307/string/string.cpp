#include<bits/stdc++.h>
using namespace std;
int n,x[2000002];
string y[2000002];
long long a;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopon("string.in","r",stdin);
    freopon("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        a+=x[i];
    }
    for(int i=2;i<=n;i++){
        if(y[i]!=y[i-1]){
            if(a%2==0){
                cout<<a/2;
            }else{
                cout<<(a-1)/2;
            }
            return 0;
        }
    }
    cout<<0;
    return 0;
}
