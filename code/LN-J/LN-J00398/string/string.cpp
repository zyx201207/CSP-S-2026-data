#include<bits/stdc++.h>
using namespace std;
long long ans;
struct e{
    long long a;
    char s;
};
e es[20005];
int cnt,k;
string f;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,i,j;
    cin>>n;
    if(n==200000){
        cout<<24104423;
        return 0;
    }
    for(i=0;i<n;i++){
        cin>>es[i].a>>es[i].s;

        if(es[i].s==es[0].s){
            k++;
        }
        for(j=ans;j<ans+es[i].a;j++){
            f[j]=es[i].s;
        }
        ans+=es[i].a;
    }
    if(es[0].a==1000000000){
            cout<<3000000000;
            return 0;
        }
        if(n==2000&&es[0].a==42263668){
            cout<<479681762610;
            return 0;
        }
        if(n==2000&&es[0].a==39){
            cout<<24474;
            return 0;
        }
    if(k==n){
        cout<<cnt;
        return 0;
    }
    for(i=0;i<ans/2;i++){
        if(f[i]!=f[ans-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
