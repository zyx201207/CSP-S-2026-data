#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
long long c,t,n,d,a[N],s;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    while(t&&t--){
        cin>>n>>d;
        s=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(long long i=1;i<=n-3;i++){
            long long j=i+3;
            for(long long l=i+1;l<j;l++){
                    if(a[l]-a[i]<=d && a[j]-a[l]<=d) s++;
            }
        }
        cout<<s<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

