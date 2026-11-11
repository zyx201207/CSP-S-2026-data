#include<bits/stdc++.h>
using namespace std;
int n,m,v=0;
vector<int> a;
int b[300005]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d",&n);
    scanf("%d",&m);
    int y=-1;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(y==-1) y=x;
        else if(y>x) v=1;
        a.push_back(x);
    }
    if(v==0){
        vector<int> c;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(!c.empty()&&c[j-1]==a[j]) c.pop_back();
                c.push_back(a[j]);
            }
            while(!c.empty()){
                b[c.back()]++;
                c.pop_back();
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<b[i]<<' ';
    return 0;
}
