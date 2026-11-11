#include<fstream>
#include<algorithm>
std::ifstream fin("crystal.in");
std::ofstream fout("crystal.out");
const int maxn=500005;
long long a[maxn];
long long tr[maxn];
long long lowbit(int x){
    return x&-x;
}
long long query(int x){
    long long ans=0;
    for(;x>0;x-=lowbit(x))
        ans+=tr[x];
    return ans;
}
int main(){
    int n;
    long long m;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        tr[i]=query(i-1)+a[i]-query(i-lowbit(i));
    long long maxans=0;
    for(int i=1;i<=n;i++){
        long long sum=(i-1)*a[i]-query(i-1);
        fout<<sum<<'\n';
        if(sum>m)
            break;
        maxans++;
    }
    fout<<maxans<<'\n';
}
