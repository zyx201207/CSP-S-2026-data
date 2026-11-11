#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
long long num[200005];long long n,m;
vector<int> cc;
bool f(int x){
    if(cc.empty()){
        return 0;
    }
    for(int i = 0;i < cc.size();i++){
        if(cc[i] == x){
            return 1;
        }
    }
    return 0;
}
int s = 0;
void dfs(int l){
    if(l == m + 1){
        int sum = cc[0];
        for(int i = 1;i < cc.size();i++){
            sum = sum & cc[i];
        }
        s = max(sum,s);
        return;
    }
    for(int i = 0;i < n;i++){
        if(!f(num[i])){
            cc.push_back(num[i]);
            dfs(l + 1);
            cc.pop_back();
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for(int i = 0;i < n;i++){
        cin >> num[i];
    }
    /*sort(num,num + n,cmp);
    long long sum = num[0];
    for(int i = 1;i < m;i++){
        sum = sum & num[i];
    }*/
    dfs(1);
    cout << s << endl;
    return 0;
}
