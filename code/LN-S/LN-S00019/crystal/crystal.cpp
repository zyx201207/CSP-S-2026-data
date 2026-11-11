#include<bits/stdc++.h>
using namespace std;
const int R = 500010;
long long a[R];
queue<long long> q;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i = 1;i <= n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    long long LT = 0,k = m,u,v,sum = 1;
    long long j=2;
    q.push(a[1]);
    while(j<=n){
        u=q.front()-a[j];
        if(u <= k){
            k-=u;
            q.push(a[j]);
            j++;
            sum++;
        }else{
            v = q.front();
            q.pop();sum--;
            k+=(v-q.front())*sum;
            if(q.empty()){
                q.push(a[j]);
                j++;sum++;
            }
        }
        LT = max(LT,sum);
    }
    cout<<LT;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*

*/
