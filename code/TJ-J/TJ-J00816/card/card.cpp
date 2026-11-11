#include <bits/stdc++.h>
using namespace std;

struct number{
    int b;
    int place;
};
int n,m;
vector<int> v;
int ans[300001];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    for(int q=0;q<n;q++){
        vector<int> vir;
        vector<number> num;
        for(int i=0;i<=m;i++){
            num.push_back({0,0});
        }
        for(int i=q;i<n;i++){
            int t=v[i];
            vir.push_back(t);
            if(num[t].b!=0){
                for(int j=num[t].place;j<=i;j++){
                    num[vir[j]].b=0;
                }
                cout<<endl;
            }
            num[t].place=i;
            num[t].b=1;
        }
        for(int p=1;p<=m;p++){
            if(num[p].b>0){
                ans[p]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
