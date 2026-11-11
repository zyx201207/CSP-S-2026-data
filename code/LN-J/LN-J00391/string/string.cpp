#include<bits/stdc++.h>
using namespace std;
int const maxn=2*1e5+10,maxm=2*1e9;
int n,a[maxn];
char s[maxn],s1[maxm];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long summ=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        for(int j=1;j<=a[i];j++){
            s1[summ+j]=s[i];
        }
        summ+=a[i];
    }
    long long ans=0;
    for(int i=1;i<=summ/2;i++){
        if(s1[i]!=s1[summ-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
