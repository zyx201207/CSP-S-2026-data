#include <bits/stdc++.h>
using namespace std;

int n,mmax;
long long m,a[500001],cha[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    bool b = true;
    for(int i = 1;i <= n;i++)
        scanf("%lld",&a[i]);
    sort(a + 1,a + n + 1);
    for(int i = 1;i < n;i++)
        cha[i] = a[i + 1] - a[i];
    for(int i = 1;i < n;i++)
        if(cha[i] != cha[1])
            b = false;
    if(b){
        int cnt = 0;
        long long sum = 0;
        while(true){
            if(sum + cnt * cha[1] >= m || cnt >= n)
                break;
            cnt++;
            sum += cnt * cha[1];
        }
        printf("%d",cnt + 1);
    }
    else{
        for(int i = 1;i < n;i++){
            int pos = i - 1,cnt = 0;
            long long sum = 0;
            while(true){
                if(sum + cnt * cha[pos] >= m || pos >= n)
                    break;
                cnt++;
                pos++;
                sum += cnt * cha[pos];
            }
            mmax = max(mmax,cnt + 1);
        }
        printf("%d\n",mmax);
    }
    return 0;
}
