#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N];
int fl[M];
int nowa[N];
int fcnt=1;
vector<int> vec;
bool check(){
    for(int i=1;i<n;i++){
        if(a[i+1]<=a[i]) return false;
    }
    return true;
}
void solve(int k){
    memset(nowa,0,sizeof(nowa));
    for(int i=k;i<=n;i++){
        int c=a[i];
        if(nowa[c]==0){
            vec.push_back(c);
            nowa[c]=1;
        }else{
            while(!vec.empty()){
                if(vec[vec.size()-1]==c){
                    break;
                }
                nowa[vec[vec.size()-1]]=0;
                vec.pop_back();
            }
        }
    }
    for(int i=0;i<vec.size();i++) fl[vec[i]]++;
    vec.clear();
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    scanf("%d %d",&n,&m);
    memset(fl,0,sizeof(fl));
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    if(check()){
        for(int i=1;i<=n;i++){
            fl[a[i]]=fcnt;
            fcnt++;
        }
        for(int i=1;i<=m;i++){
            printf("%d ",fl[i]);
        }
        return 0;
    }

    for(int i=1;i<=n;i++){
        solve(i);
    }
    for(int i=1;i<=m;i++){
        printf("%d ",fl[i]);
    }
    return 0;
}
