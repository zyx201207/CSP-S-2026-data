#include<bits/stdc++.h>
using namespace std;
const int MAXE=5e5+100;
long long a[MAXE];
int n;
long long m;
queue<long long> q;
int maxe=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    q.push(a[0]);
    long long total=0;
    for(int i=1;i<n;i++){
        total+=(a[i]-q.back())*((int)q.size());
        while(m<total&&!q.empty()){
            total-=(a[i]-q.front());
            q.pop();
        }
        q.push(a[i]);
        maxe=max(maxe,(int)q.size());
    }
    printf("%d",maxe);
    return 0;
}