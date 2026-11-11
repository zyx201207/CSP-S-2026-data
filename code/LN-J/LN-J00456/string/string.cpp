#include<bits/stdc++.h>
using namespace std;
long long int n;
char ch[1000001];
long long int a[1000001];
long long int sum,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>ch[i];
        sum+=a[i];
        for(int j=1;j<=a[i];j++){
            s+=ch[i];
        }
    }
    for(int i=0;i<sum/2;i++){
        if(s[i]!=s[sum-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
