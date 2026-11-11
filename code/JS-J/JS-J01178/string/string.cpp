#include<iostream>
using namespace std;
const int N=2e5+10;
int n;
long long ans,l,a[N];
char c[N];
string s="A";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }

        l+=a[i];
    }
    int mid;
    if(l%2==1){
        mid=l/2+1;
    }
    else mid=l/2;
    for(int i=1;i<=mid;i++){
        if(s[l-i+1]!=s[i]){
            ans++;
        }
    }
    cout<<ans;
}
