#include<bits/stdc++.h>
std::ifstream fin("card.in");
std::ofstream fout("card.out");
int a[500001];
int b[300001]={0};
int main(){
    int n,m;
    fin>>n>>m;
    std::deque<int> q;
    int cnt=0;
    for(int i=0;i<n;++i){
        fin>>a[i];
    }
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            for(int k=i;k<j;++k){
                if(a[k]==a[j]){
                    for(int h=0;h<j-k;++h){
                        q.pop_back();
                    }
                }
            }
            q.push_back(a[j]);
        }
        for(int j=0;j<q.size();++j){
            cnt=q.back();
            b[cnt-1]++;
            q.pop_back();
        }
        q.clear();
    }
    for(int i=0;i<m;++i){
        fout<<b[i]<<" ";
    }
}
