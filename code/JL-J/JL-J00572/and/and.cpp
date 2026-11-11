#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<long long> vec;
    int n,m;
    long long a;
    cin>>n>>m;
    for(int i=0;i<n;i++    long long a;
){
        cin>>a;
        vec.push_back(a);
    }
    int out=-1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(vec[i]&vec[j]>out){
                out=vec[i]&vec[j];
            }
        }
    }
    cout<<out;
    return 0;
}
