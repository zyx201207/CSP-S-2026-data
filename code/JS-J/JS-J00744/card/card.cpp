#include<fstream>
#include<vector>
#include<algorithm>
std::ifstream fin("card.in");
std::ofstream fout("card.out");
int main(){
    int n,m;
    fin>>n>>m;
    std::vector<int>a(n);
    for(int i=0;i<n;i++){
        fin>>a[i];
    }
    std::vector<int>out(m+1,0);
    for(int i=0;i<n;i++){
         std::vector<bool>out2(m+1,0);
        for(int j=i;j<n;j++){
            out2[a[j]]=1;
        }
        for(int j=1;j<=m;j++){
            out[j]+=out2[j];
        }
    }
    for(int j=1;j<=m;j++){
        fout<<out[j]<<' ';
    }
}
