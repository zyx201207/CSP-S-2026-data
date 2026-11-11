#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    vector<int> num;
    int n,m,ans;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }
    sort(num.begin(),num.end(),cmp);
    ans=num[0];
    for(int j=1;j<m;j++){
        int tmp=num[j];
        ans=ans & tmp;
    }
    cout << ans;
    return 0;
}