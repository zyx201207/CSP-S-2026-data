#include <bits/stdc++.h>
using namespace std;

int main(){
    #define int long long
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        vector<int> pos(n);
        for(int i=0;i<n;i++){
            cin>>pos[i];
        }
        vector<vector<int>> memory(n,vector<int>(n,-1));
        vector<vector<int>> wayLen(n,vector<int>(n,-1));
        function<int(int,int)> waysBetweenTwo=[&](int x,int y){
            if(memory[x][y]!=-1) return memory[x][y];
            if(y-x==1) return wayLen[x][y]=1,memory[x][y]=(pos[y]-pos[x]<=d?1:0);
            if(pos[y]-pos[x]<=d) return wayLen[x][y]=1,memory[x][y]=1;
            int ret=0;
            int bestLen=INT_MAX;
            for(int i=1;i<=y-x-1;i++){
                if(min(bestLen,wayLen[x][x+i]+wayLen[x+i][y])!=bestLen){
                    bestLen=min(bestLen,wayLen[x][x+i]+wayLen[x+i][y]);
                    ret=0;
                }
                if(wayLen[x][x+i]+wayLen[x+i][y]==bestLen)
                    ret+=waysBetweenTwo(x,x+i)*waysBetweenTwo(x+i,y);
            }
            return memory[x][y]=ret;
        };
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(waysBetweenTwo(i,j)==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    #undef int
    return 0;
}
// ________  ________
//|  ____  ||  ____  |   __      __    __
//| |____| || |____| | _|  |_  _|  |_ |__|
//|  ____  ||  ______||_    _||_    _| __
//|_|    \_\|_|         |__|    |__|  |_/
//    R         P        +       +     ;