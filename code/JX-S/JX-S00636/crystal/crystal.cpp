#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int nl[50005]={},he[50005]={},cha[50005]={},sum=0,sj[50005]={},bj=0,ee;
    for (int i=1;i<=n;i++){
        cin>>nl[i];
        cha[i-1]=nl[i]-nl[i-1];
    }

    for (int i=1;i<=n&&m>0;i++){
        if(cha[i]<cha[i-1]){
            cha[i]+=1;
            m--;
        }
        if(cha[i]=cha[i+1])
            sum++;
    }
    cout<<sum;
    return 0;
}
