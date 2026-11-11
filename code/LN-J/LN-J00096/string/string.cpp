#include<bits/stdc++.h>
using namespace std;
long long a[10000010];
char b[10000010];
string c;
int main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n; cin>>n;
    long long ans=0;
    long long ant=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        cin>>b[i];
        ans+=a[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=a[i];++j){
            c=c+b[i];
        }
    }
    for(int i=0;i<=(ans+1)/2-1;++i){
        if(i==ans-1-i){
            ant+=0;
        }
        else if(c[i]!=c[ans-1-i])ant+=1;
    }
    cout<<ant<<endl;

    return 0;
}
