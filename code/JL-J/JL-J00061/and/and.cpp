#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxcnt=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        long long cnt=a[i]&a[i+1];
        if(cnt>maxcnt){
            maxcnt=cnt;
            cnt=0;
        }
    }
    cout<<maxcnt;
    return 0;
}

