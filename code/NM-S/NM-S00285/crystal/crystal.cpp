#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int N = 5e5+1;
long long a[N];
bool cmp(long long x , long long y){
    return x >y;
}
int u;
int cnt1 = 1;
long long f , sum ,f1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >>m;
    sum = m;
    for(int i = 1; i <= n; i++)
        cin >>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i = 1; i <= n; i++){
        if(a[1]-a[i]<=sum){
            sum -= a[1]-a[i];
            f++;
            u = i;
        }
        if(sum < a[1]-a[i])
            break;
    }
    f1 = f;
    for(int i = 1; i<= n;){
        int cnt =i;
        int boo = 1;
        while(a[cnt] == a[cnt+1] && cnt < n){
            cnt++;
            boo++;
        }
        sum += (f-boo) *(a[cnt] - a[cnt+1]);
        f-=boo;
        while(a[cnt+1] - a[u+1] <= sum){
            sum -=(a[cnt+1]-a[u+1]);
            f++;
            u++;
            if(u > n)   break;
        }
        f1 = max(f1,f);
        i = cnt+1;
        if(u >n) break;
    }
    cout << f1;
    return 0;
}
