#include<fstream>
std::ifstream fin("and.in");
std::ofstream fout("and.out");
using i64=long long;
int n,m;
i64 a[200005];
i64 solve(int i,int k,i64 sum){
    if(i==n){
        if(k==m)return sum;
        else return 0;
    }
    if(k==m)return sum;
    int drop=solve(i+1,k,sum);
    int pick=0;
    if(k==0)pick=solve(i+1,k+1,a[i]);
    else pick=solve(i+1,k+1,sum & a[i]);
    return std::max(pick,drop);
}
int main()
{
    fin>>n>>m;
    for(int i=0;i<n;i++){
        fin>>a[i];
    }
    fout<<solve(0,0,0);
}
