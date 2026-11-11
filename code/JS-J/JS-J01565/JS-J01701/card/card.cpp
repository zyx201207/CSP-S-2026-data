#include<fstream>
#include<cstring>
#include<vector>
using namespace std;
long long n,m;
int a[500010],b[300010];
bool vis[300010];

int main(){
    ifstream fin("card.in");
    ofstream fout("card.out");
    
    fin >> n >> m;
    for(int i = 1;i <= n;i++){
        fin >> a[i];
        b[a[i]] = i;
    }
    for(int i = 1;i <= n;i++){
        if(vis[a[i]]){
           b[a[i]]-=i; 
        }else{
            vis[a[i]] = true;
        }
    }
    for(int i = 1;i <= m;i++){
        fout << b[i]<<" ";
    }


    fin.close();
    fout.close();
    return 0;
}