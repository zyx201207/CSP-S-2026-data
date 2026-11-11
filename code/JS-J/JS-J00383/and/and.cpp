#include<bits/stdc++.h>
using namespace std;
long long a,zy;
int n,i,j,m,x,d;
vector<int> yu[32];
int c[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a;j=0;
        while(a>0){
            if(a%2==1)yu[j].push_back(i);
            a/=2;
            j++;
        }
    }
    i=30;
    while(i>=0&&yu[i].size()<m)
        i--;
    if(i==-1){
        cout<<0;
        return 0;
    }
    zy+=(1<<i);
    for(j=0;j<yu[i].size();j++)
        c[yu[i][j]]=1;
    d=1;
    for(i=i-1;i>=0;i--)
        if(yu[i].size()>=m){
            x=0;
            for(j=0;j<yu[i].size();j++)
                if(c[yu[i][j]]>=d)
                    x++;
            if(x>=m){
                zy+=(1<<i);
                for(j=0;j<yu[i].size();j++){
                    if(c[yu[i][j]]==d)
                        c[yu[i][j]]++;
                }
                d++;
            }
    }
    cout<<zy;
    return 0;
}
