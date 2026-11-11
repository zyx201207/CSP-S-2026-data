#include<fstream>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int MAXN=5e5+5;

ifstream fin("crystal.in");
ofstream fout("crystal.out");

int n,m;
int presum[MAXN],a[MAXN];

signed main(){
    fin>>n>>m;
    for(int i=1;i<=n;++i){
        fin>>a[i];
        a[i]+=1e12;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        presum[i]=a[i]+presum[i-1];
    }
    int head=1,tail=2;
    int res=0;
    while(head<=tail-1){
        // len:tail-head+1
        // sum:presum[tail-1]-presum[head-1]
        while((presum[tail]-presum[tail-1])*(tail-head)-(presum[tail-1]-presum[head-1])<=m){
            ++tail;
        }
        res=max(res,tail-head);
        while((presum[tail]-presum[tail-1])*(tail-head)-(presum[tail-1]-presum[head-1])>m){
            ++head;
        }
    }
    fout<<res<<endl;
    return 0;
}