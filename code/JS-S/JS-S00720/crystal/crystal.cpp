#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long m,n;
    cin>>n>>m;
    long long c[500050];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    int mxcnt=1;
    for(int i=0;i<n;i++){
        int tcnt=1;long long tm=m;
        for(int j=i-1;j>-1;j--){
            if(tm>=c[i]-c[j]){
                tm-=c[i]-c[j];tcnt++;
            }
            else break;
        }
        mxcnt=max(tcnt,mxcnt);
    }
    cout<<mxcnt;
    return 0;
}
