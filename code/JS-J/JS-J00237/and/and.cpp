#include<fstream>
using namespace std;
int a[200005];
ifstream fin("and.in");
ofstream fout("and.out");
int main(){
    long long n,m;
    fin>>n>>m;
    for(int i=0;i<n;i++)fin>>a[i];
    long long best=a[0];
    if(m==2){
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++){
                int x=(a[i] && a[j]);
                if( best <= x )
                    best = x;
            }
    }
    if(m==1){
        for(int i=1;i<n;i++){
            best=best && a[i];
        }
    }
    fout<<best;
    return 0;
}
