#include<bits/stdc++.h>
using namespace std;

long long n,a[100000010],ans;
char c[100000010];
string s;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=0;j<a[i];j++)s+=c[i];
    }
    long long p=0,q=s.length()-1;
    while(p!=q){
        if(s[p]!=s[q])ans++;
        p++;
        q--;
    }
    cout<<ans<<"\n";
    return 0;
}
