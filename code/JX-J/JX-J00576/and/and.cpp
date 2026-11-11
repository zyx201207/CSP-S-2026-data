#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,max_n=0;
    cin>>n>>m;
    int cm=m;
    int r=0;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]){
            cout<<a[i]<<'\n';
            return 0;
        }
    }

    for(int i=n-1;i>=0;i++){
        while(m){
            if(cm!=m){
                m--;
                r&=a[i-2];
                if(!m) max_n=max(max_n,r);
            }else{
                r=a[i]&a[i-1];
                m-=2;
                if(!m) max_n=max(max_n,r);
            }
        }
    }
    cout<<max_n<<'\n';
    return 0;
}
