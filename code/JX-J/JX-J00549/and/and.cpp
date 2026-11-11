#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200001],maxz=LLONG_MIN;
void f(int x,int y,bool yy);
vector<int> v;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f(1,1,true);
    cout<<maxz;
    return 0;
}
void f(int x,int y,bool yy){
    if(x==n+1||y==m+1){
        if(y==m+1){
            long long z,a=1;
            for(auto o:v){
                if(a==1){
                    a=0;
                    z=o;
                }else{
                    z=z&o;
                }
            }
//            cout<<"-->"<<z<<endl;
            maxz=max(maxz,z);
        }
        return;
    }
    v.push_back(a[x]);
    f(x+1,y+1,yy);
    v.pop_back();
    f(x+1,y,yy);
}
