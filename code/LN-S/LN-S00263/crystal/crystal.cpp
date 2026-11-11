#include<bits/stdc++.h>
using namespace std;
vector<long long>cry;
vector<long long>suan;
vector<int>tot;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m,sc,mm,cz;
    scanf("%d %lld",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&sc);
        cry.push_back(sc);
    }
    sort(cry.begin(),cry.end());
    for(int i=1;i<n;i++){
        scanf("%lld",&sc);
        suan.push_back(cry[i]-cry[i-1]);
    }
    int j;
    for(int i=0;i<n-1;i++){
        mm=m;cz=0;
        for(j=i;j>=0;j--){
            cz+=suan[j];
            mm-=cz;
            if(mm<0){
                break;
            }
        }
        tot.push_back(i-j+1);
    }
    sort(tot.begin(),tot.end());
    printf("%d",tot[n-2]);
    return 0;
}
