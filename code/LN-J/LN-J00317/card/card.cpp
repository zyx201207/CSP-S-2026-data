#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],l[100005];
vector<int> p;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            p.push_back(a[j]);
            for(int k=0;k<p.size()-1;k++){
                if(p[k]==p[p.size()-1]){
                    for(int v=k;v<=p.size()-2;v++){
                        p[v]=0;
                    }
                }
            }
        }
        for(int k=0;k<=p.size()-1;k++){
            l[p[k]]++;
        }
        while(!p.empty()){
            p.pop_back();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<l[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
