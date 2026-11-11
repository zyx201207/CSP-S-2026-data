#include<bits/stdc++.h>
using namespace std;
int bucket[31];
set<int> provider[31];
set<int> ans_provider;
int ans_provider_lst[200010];
bool flag=true;
int p(int x){
    int res=1;
    for(int i=0;i<x;i++){
        res*=2;
    }
    return res;
}
int set_and(int level){
    int command_size=ans_provider.size();
    int s=provider[level].size();
    //cout<<s<<' ';
    for(int i=0;i<ans_provider.size();i++){
        provider[level].insert(ans_provider_lst[i]);
        int b=provider[level].size();
        if(s!=b){
            command_size--;
        }
    }
    //cout<<command_size<<' ';
    return command_size;
}
int main(){
    int ans=0;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdin);
    memset(bucket,0,sizeof(bucket));
    int n,m;cin>>n>>m;
    int a[200020];
    for(int i=0;i<n;i++){
        cin>>a[i];
        int c=1;
        if(a[i]%2){
            bucket[0]++;
            provider[0].insert(a[i]);
        }
        for(int j=1;j<31;j++){
            c*=2;
            if(a[i]/c%2){
                bucket[j]++;
                provider[j].insert(a[i]);
            }
        }
    }
    for(int i=30;i>-1;i--){
        if(bucket[i]>=m){
            if(flag){
                flag=false;
                ans_provider=provider[i];
                int l_i=0;
                for(int k=0;k<n;k++){
                    if(a[k]/p(i)%2){
                        ans_provider_lst[l_i++]=a[k];
                        //cout<<ans_provider_lst[l_i-1]<<' '<<endl;
                    }
                }
            }
            if(set_and(i)>=m){
                //cout<<endl<<provider[i].size();
                ans+=p(i);
            }
        }
    }
    cout<<ans;
}
