#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+10;
int a[N];
vector<int> v;
int found(int key,int fi){
    int i=fi;
    for(int j=0;j<m&&i>=0;j++,i--){
        if(v[i]==key){
            return i;
        }
    }return -1;
}
int main(){
    freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    //
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ju=1;//di yi ju
    for(int i=ju;i<=m;i++){
        v.push_back(a[i]);

        int aaa=found(a[i],i);
        if(aaa!=-1){
            for(int k=0;k<aaa;k++){
                v.erase(v.begin()+i-k);
            }
        }
    }

    return 0;
}
