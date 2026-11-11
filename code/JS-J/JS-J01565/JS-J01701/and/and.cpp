#include<fstream>
#include<cmath>
using namespace std;
long long n,m,Max = -1,all = 0;
long long a[200010];

int dfs(int pos,long long bit,int res){
    if(pos==m)return res;
    else{
        int ans = -1;
        for(int i = 1;i <= n;i++){
            if((bit >> (i-1)) & 1)continue;
            ans = max(dfs(pos+1,bit | (1<<(i-1)),res & a[i]),ans);
        }
        return ans;
    }
}

int main(){
    ifstream fin("and.in");
    ofstream fout("and.out");
    fin >> n >> m;
    
    for(int i = 1;i <= n;i++){
        fin >> a[i];
        Max = max(Max,a[i]);
        all = (a[i] & all);
    }
    if(m == 1)fout <<Max;
    else if(m == n)fout << all;
    else if(n <= 20){
        long long tmp = (1>>25)-1;
        fout << dfs(0,0,Max);
    }else{
        long long  ans = -1;
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                ans=max(ans,a[i] & a[j]);
            }
        }
        fout << ans;
    }

    fin.close();
    fout.close();
}