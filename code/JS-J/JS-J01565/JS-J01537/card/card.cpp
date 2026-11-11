#include<bits/stdc++.h>
using namespace std;
int a[500010];
unordered_map<int,int>mp;
unordered_map<int,int>ans;
int n,m;
void f(){
    for(int i=1;i<=m;i++)cout<<n<<' ';
}
bool find(vector<int>&v,int m)
{
	for(auto&&x:v)if(x==m)return 1;
	return 0;
}
void ml(){   
    for(int l=1;l<=n;l++){
		unordered_map<int,int>first;
		vector<int>v;    
        for(int i=l;i<=n;i++){
            if(find(v,a[i])){
                for(int j=v.size()-1;j>=first[a[i]];j--)v.erase(v.begin()+j);
            }
            v.push_back(a[i]);     
            first[a[i]]=v.size()-1;
        } 
        for(auto&&x:v){
			ans[x]++;		
		}	
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(mp[a[i]]){
            flag=0;
        }
        mp[a[i]]=i;
    }
    if(flag){
        f();
        return 0;
    }
    ml();
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
