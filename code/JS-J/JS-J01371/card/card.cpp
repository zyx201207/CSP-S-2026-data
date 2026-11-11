#include<bits/stdc++.h>
using namespace std;
vector<int>a,cd;
int ans[500001];
map<int,bool>h;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n,j,xza=1;
    cin>>n>>m>>j;
    a.push_back(j);
    for(int i=1;i<n;i++){
        cin>>j;
        a.push_back(j);
        if(a[i-1]>j)xza=0;
    }
    if(xza || m==n){//special judge :D
        for(int i=0;i<n;i++)
            ans[a[i]]=i+1;
    }else
    for(int T=0;T<n;T++){
        int ed=0;
        for(int i=T;i<n;i++){
            if(h[a[i]]){
                for(j=0;j<ed;j++){
                    if(cd[j]==a[i])ed=j;
                }
            }
            //clog<<"[d]  add "<<a[i]<<endl;
            if(ed ==cd.size())cd.push_back(a[i]);
            cd[ed]=a[i];
            ed++;
            h[a[i]]=1;
        }
        //map<int,bool>::iterator it=h.begin();
        for(int i=0;i<ed;i++){
            ans[cd[i]]+=1;
        }
        h.clear();cd.clear();
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
}
