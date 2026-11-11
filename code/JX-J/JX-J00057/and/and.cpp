#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> nums;
vector<long long> ans;
vector<long long> S;
void dfs(int x){
    if(x>m){
        int num=nums[0];
        for(int i=1;i<m;i++)
            nums[i]&=num;
        ans.push_back(num);
        vector<long long> nums;
    }
    for(int i=x;i<n;i++){
        nums.push_back(S[i]);
        dfs(++x);
    }
}
int main(){
    (stdin,"and.in",cin);
    (stdout,"and.out",cout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        S.push_back(a);
    }
    dfs(0);
    sort(ans.begin(),ans.end());
    cout<<ans[ans.size()-1];
    return 0;
}
