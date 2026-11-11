#include<fstream>
#include<vector>
#include<algorithm>
std::ifstream fin("crystal.in");
std::ofstream fout("crystal.out");
int main(){
    long long n,m,out=0;
    fin>>n>>m;
    std::vector<long long>a(n);
    fin>>a[0];
    for(long long i=1;i<n;i++){
        fin>>a[i];
    }
    std::sort(a.begin(),a.end());
    long long leftsum=0,left=0;
    for(long long i=0;i<n;i++){
        if(left>0){
            leftsum+=(a[i]-a[i-1])*left;
            leftsum+=a[i]-a[i-1];
            left++;
        }
        while(leftsum>m){
            leftsum-=a[i]-a[i-left];
            left--;
        }
        while(i-left-1>=0&&leftsum+a[i]-a[i-left-1]<=m){
            leftsum+=a[i]-a[i-left-1];
            left++;
        }
        out=std::max(out,left+1);
    }
    fout<<out;
}
