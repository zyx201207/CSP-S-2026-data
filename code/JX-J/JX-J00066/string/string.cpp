//Math           NO TLE
//TLE
#include<iostream>
#include<vector>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    vector<char>s;int m;cin>>m;//string->vector
    for(auto i=0;i<m;i++){
        int tmp;char a;
        cin>>tmp>>a;
        for(auto j=0;j<tmp;j++){
            s.push_back(a);
        }//init
    }
    auto cnt=s.size();
    auto does=0;
    int left=0; //NO PTR
    int right=s.size()-1;
    if(s.size()%2==0){
        //run
        while(cnt!=0){
            if((s[left])!=(s[right])){
                does++;
            }
            cnt-=2;left++;right--;
        }
    }
    else{
        while(!(left==right)){
            if((s[left])!=(s[right])){
                does++;
            }
            left++;right--;
        }
    }
    cout<<does;
    return 0;
}