#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5;
int n,m;
int a[N]={0};
bool b[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int sum=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    };
    int x=n;*m;
    int ans=0,sum=0,s=0,max1=0;
    bool f=0;
    while(x){
        if(ans==m){
            for(int i=0;i<n;i++){
                if(f==0){ sum=a[i]; f=1; }
                if(b[i]==1) sum=sum&a[i];
            }
            max1=max(sum,max1);
            sum=0;
            b[ans]=0;
            ans--;
            s++;
            f=0;
            x-=1;
            continue;
        }
        s++;
        b[s]=1;
        ans++;
        x-=1;
    }
    cout<<max1<<endl;
    return 0;
}
