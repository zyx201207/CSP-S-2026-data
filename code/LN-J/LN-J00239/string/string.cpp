#include<bits/stdc++.h>
using namespace std;
int n;
long long a,l,r,sum;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(long long i=1;i<=a;i++){
            s+=c;
        }
        r+=a;
    }
    l=0;
    r--;
    while(l<=r){
        if(s[l]!=s[r]){
            sum++;
        }
        l++;
        r--;
    }
    cout<<sum;
    return 0;
}
