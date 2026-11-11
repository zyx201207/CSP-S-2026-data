#include<fstream>
int main(){
    std::ifstream fin("and.in");
    std::ofstream fout("and.out");
    int n,m;
    int a[1000005];
    for(int i=1;i<=n;i++){
        fin>>a[i];
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i and j>=sum){
                sum==i and j;
            }
        }
    }
    fout<<sum<<"\n";
}
