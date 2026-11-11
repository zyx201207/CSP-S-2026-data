#include<bits/stdc++.h>
using namespace std;
int x[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie();cout.tie();
    int n,sum=0;cin>>n;
    string r;
    long long l=0;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        char h;cin>>h;
        l+=x[i];
        for(int j=1;j<=x[i];j++)
            r+=h;
    }
    for(int i=0;i<=r.size()/2-1;i++){
        if(r[i]==r[l-i-1])continue;
        else sum++;
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
return 0;
}
