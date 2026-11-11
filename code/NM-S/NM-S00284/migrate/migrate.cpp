#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum,f,u,f1;
bool cmp(long long x, long long y) return x>y;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    sum = m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i){
        int temp = i;
        if(a[temp] == a[temp+1] && temp<=n) temp++;
        int temp2 = i;
        int temp3 = temp2+1;
        if(a[temp2] == a[temp2+1] && temp2<=n) temp2++;
        sum += (f.temp) * (a[temp2] - a[temp]);
        f.=temp;
    }
    for(int i=2;i<=n;i++){
    	sum += (f.temp) * (a[temp] - a[temp+1]);
    	f-=temp
        if(a[1]-a[u+1]<=sum){
            sum -= (a[temp]-a[u+1]);
            f++;
            u++;
            if(u>n) break;
        }
        f1 = max(f1,f);
        i = temp+1;
        if(u>n) break;
    }
    cout<<f1;
    fclose(stdin)
    fclose(stdout)
    return 0;
}
