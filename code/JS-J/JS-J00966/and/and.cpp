#include<bits/stdc++.h>
using namespace std;
vector<int> v;
bool choice[100010];
int n,m;
const int max_num=pow(2,31)-1;
int dfs(int crt_and,int rest){
    //and:current and num. max_and:max and num. rest:how much turns to choose.
    if(rest==0) return crt_and;
    if(crt_and==0) return 0;
    int max_and=-1;
    for(int i=0;i<n;i++){
        if(choice[i]==false){
            choice[i]=true;
            //cout<<"rest: "<<(rest-1)<<" chosen: "<<v[i]<<" value: "<<(crt_and&v[i])<<endl;
            if(v[i]==0) continue;
            int dfs_res=dfs(crt_and&v[i],rest-1);
            int crt_res=crt_and&dfs_res;
            choice[i]=false;
            //cout<<"dfs result: "<<dfs_res<<" current and: "<<crt_and<<" current result: "<<crt_res<<" release rest: "<<rest<<endl;
            max_and=max(max_and,crt_res);
            //cout<<"depth: "<<m-rest+1<<" current max and: "<<max_and<<endl;
        }
    }
    //cout<<"--------------------"<<endl;
    //cout<<"return to depth "<<m-rest+1<<endl;
    //cout<<"--------------------"<<endl;
    return max_and;
}
int main(){
    //freopen("/home/user/Desktop/and/and5.in","r",stdin);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        v.push_back(temp);
    }
    //cout<<n<<" "<<m<<endl;
    //for(int i=0;i<n;i++){
    //    cout<<v[i]<<" ";
    //}
    //cout<<endl;
    cout<<dfs(max_num,m)<<endl;
    return 0;
}
