#include<fstream>
#include<vector>
#include<algorithm>
std::ifstream fin("and.in");
std::ofstream fout("and.out");
int main(){
    int n,m,out2=0;
    fin>>n>>m;
    std::vector<int>a(n);
    for(int i=0;i<n;i++){
        fin>>a[i];
    }
    std::sort(a.begin(),a.end());
    for(int i=n-1;i>=m-1;i--){
            if(out2>=a[i-m+1]){
                break;
            }
        int lin=a[i];
        for(int j=1;j<m;j++){
            lin=lin&a[i-j];

        }
        out2=std::max(out2,lin);
    }
    fout<<out2;
}
