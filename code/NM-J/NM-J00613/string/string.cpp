#include<bits/stdc++.h>
using namespace std;
long long n,sum=0;
char bc;
string s,ns;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    bool flag=true;
    for(int i=1;i<=n;i++){
        long long k;
        cin>>k;
        sum+=k;
        char c;
        cin>>c;
        if(i==1) bc=c;
        else{
            if(c!=bc) flag=false;
        }
    }
    if(flag) cout<<0<<endl;
    sum/=2;
    cout<<sum<<endl;
    return 0;
}
