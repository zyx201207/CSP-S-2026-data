#include<fstream>
#include<vector>
#include<algorithm>
std::ifstream fin("migrate.in");
std::ofstream fout("migrate.out");
int main(){
    long long c,t;
    fin>>c>>t;
    while(t--){
        long long n,d;
        fin>>n>>d;
        if(n==1){
            fout<<0<<std::endl;
        }
        std::vector<long long>a(n);
        for(long long i=0;i<n;i++){
            fin>>a[i];
        }
        long long cha=a[1]-a[0];
        if(d>=cha+cha&&d<cha+cha+cha){
            if(n>=4){
                fout<<n-4+1<<std::endl;
            }else{
                fout<<0<<std::endl;
            }
        }else{
            fout<<0<<std::endl;
        }
    }
}
