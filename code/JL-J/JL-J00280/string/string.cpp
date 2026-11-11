#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long a[N],sum=0,ans=0;
char s[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int p=1;
    for(int i=1;i<=n;i++){
        int x;char c;
        cin>>x>>c;
        for(int i=0;i<x;i++)s[i+p]=c;
        p+=x;
    }p-=1;
    //for(int i=1;i<=p;i++)cout<<i<<':'<<s[i]<<endl;
    for(int z=1;z<=p/2;z++){
        if(s[z]!=s[p+1-z]){
            ans++;
        }
    }
    cout<<ans;

    return 0;
}
