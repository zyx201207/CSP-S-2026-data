#include<fstream>
int n,m;
int a[200005];
int solve(int s,int c){
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]==a[j]){
                sum++;
            }
        }
        return sum;
    }
}
int main(){
    std::ifstream fin("card.in");
    std::ofstream fout("card.out");
    fin>>n>>m;
    for(int i=1;i<=n;i++){
        fin>>a[i];
    }
    for(int i=1;i<=n;i++){
        fout<<solve(n,m)<<" ";
    }
}
