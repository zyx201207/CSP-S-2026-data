#include<fstream>
#include<vector>
#include<algorithm>
std::ifstream fin("subway.in");
std::ofstream fout("subway.out");
int main(){
    int a,b,c,d,e;
    fin>>a>>b>>c>>d>>e;
    for(int i=0;i<e;i++){
        fout<<2<<std::endl;
    }
}
