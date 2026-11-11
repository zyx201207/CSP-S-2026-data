#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int i=1;
    while(m){
        if(i>=n)m=0;
        for(int j=1;j<=i;j++){
            a[j]++;
            m--;
        }
        if(a[i]==a[i+1]){
            for(int j=i;j<=n;j++){
                if(a[j]==a[j+1])i++;
                else break;
            }
        }
    }
    cout<<i;
    return 0;
}
