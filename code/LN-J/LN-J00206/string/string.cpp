#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string b[200005],c[100000005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >>n;
    long long m=0;
    for(int i=1;i<=n;i++){
        cin >>a[i]>>b[i];
        string num=b[i];
        for(int i=m;i<m+a[i];i++)c[i]=num;
        m+=a[i];
    }
    if(n==1){
        cout <<0;
        return 0;
    }
    if(n==2){
        cout <<min(a[1],a[2]);
        return 0;
    }
    long long ans=0;
    for(long long i=0;i<m;i++){
        if(c[i]!=c[m+1-i])ans++;
    }
    cout <<ans;
    return 0;
}
