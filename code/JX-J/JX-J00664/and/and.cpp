#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=-1,p,x,y,q,h;
vector<int> arr[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>h;
        arr[i]=h;
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                p=arr[i]&(arr.begin()+j);
                q=maxn;
                maxn=max(maxn,p);
                if(q!=maxn){
                    x=i;
                    y=j;
                }
            }
        }
        arr.begin()+i
    }
    cout<<maxn;
    return 0;
}
