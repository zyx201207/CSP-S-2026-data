#include <bits/stdc++.h>
using namespace std;
int n,m,g;
unsigned long long s;
bool a[200010][64];
unsigned long long b[65];
vector<int>k[65];
bool f[200010];
int p;
vector<int>x[65];
long long z;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    b[1]=1;
    for(int i=1;i<=n;i++)f[i]=true;
    for(int i=2;i<=64;i++){b[i]=b[i-1]*2;}
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=64;j>=1;j--){
            if(s>=b[j]){
                s-=b[j];
                a[i][j]=1;
                k[j].push_back(i);
            }
        }
    }
    for(int i=64;i>=1;i--){
        if(k[i].size()>=m){
            p=i;
            for(int j=0;j<k[i].size();j++){
                x[i].push_back(k[i][j]);
            }
            z+=b[i];
            break;
        }
    }
    for(int i=p-1;i>=1;i--){
        if(k[i].size()>=m){
            g=0;
            for(int j=0;j<x[p].size();j++){
                if(a[x[p][j]][i]){
                    g++;
                    x[i].push_back(x[p][j]);
                }
            }
            if(g>=m){
                p=i;
                z+=b[i];
            }
        }
    }
    cout<<z;
    return 0;
}
