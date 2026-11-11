#include<fstream>
#include<vector>
std::ifstream fin("card.in");
std::ofstream fout("card.out");
int n,m;
int a[500005];
int cnt[300005];
bool used[300005];
std::vector<int>adj;
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++){
        fin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<adj.size();j++){
            adj[j]=0;
        }
        for(int j=1;j<=m;j++)used[j]=false;
        for(int j=i;j<=n;j++){
            if(used[a[j]]==false){
                used[a[j]]=true;
                adj.push_back(a[j]);
            }
            else{
                int pos=0;
                for(int k=0;k<adj.size();k++){
                    if(adj[k]==a[j]){
                        pos=k;
                        break;
                    }
                }
                while(adj.size()!=pos+1){
                    adj.pop_back();
                }
            }
        }
        for(auto item:adj){
            cnt[item]++;
        }
    }
    for(int i=1;i<=m;i++){
        fout<<cnt[i]<<" ";
    }
}
