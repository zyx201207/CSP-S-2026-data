#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<int>binary;
    for(auto i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        binary.push_back(tmp);
    }
    auto p=max_element(binary.begin(),binary.end());
    int cnt=*p;
    binary.erase(p);
    //p=NULL;
    for(auto i=1;i<m;i++){
        p=max_element(binary.begin(),binary.end());
        cnt=(cnt&(*p));
        binary.erase(p);
        //=NULL;
    }
    cout<<cnt<<' ';
    return 0;
}