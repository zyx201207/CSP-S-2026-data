#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum1,sum;
bool cmp(int q,int w){
    return q<w;
}
int qwer(int w){
    int k=m,sum2=0;
    for(int i=w;i>=1;i--){
        if(k>=(a[w]-a[i])){
            k-=a[w]-a[i];
            sum2++;
        }else{
            break;
        }
    }
    return sum2;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        sum1=qwer(i);
        sum=max(sum1,sum);
    }
    cout << sum;
    return 0;
}
