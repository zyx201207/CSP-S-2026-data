#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],x=-1;
string s[1000005],k="0";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m;
    if(m==1){
        for(long long i=1;i<=n;i++){
            cin>>s[i];
            if(s[i]>k){
                k=s[i];
            }
        }
        cout<<k;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
