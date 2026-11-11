#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int a[N],lst[5010],n,m,idx,res[M],cnt[N];
vector<int> tmp;
void init(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
}
bool check(){
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]) return 0;
    }
    return 1;
}
int main(){
    init();
    //freopen("card5.in","r",stdin);
    //freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=5000){
        for(int i=1;i<=n;i++){
            memset(lst,-1,sizeof(lst));
            idx=0;
            for(int j=i;j<=n;j++){
                 if(lst[a[j]]==-1) tmp.push_back(a[j]),lst[a[j]]=tmp.size()-1;
                 else{
                    while(tmp[tmp.size()-1]!=a[j]) lst[tmp[tmp.size()-1]]=-1,tmp.pop_back();
                 }
            }
            for(int j=1;j<=m;j++){
                if(lst[j]!=-1) res[j]++;
            }
        }
        for(int i=1;i<=m;i++) cout<<res[i]<<" ";
        cout<<"\n";
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            if(a[i]==a[n]) res[a[i]]++;
            else res[1]++,res[2]++;
        }
        cout<<res[1]<<" "<<res[2]<<"\n";
    }
    else if(check()){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i+1]) cout<<i<<" ";
        }
        cout<<"\n";
    }
    else{
        for(int i=1;i<=n;i++){
            int j=i;
            while(j<=n&&a[i]==a[j]) j++;
            cnt[i]=j-i,i=j-1;
        }
        for(int i=1;i<=n;i+=cnt[i]){
            for(int j=1;j<=m;j++) lst[j]=-1;
            idx=0;
            for(int j=i;j<=n;j++){
                 if(lst[a[j]]==-1) tmp.push_back(a[j]),lst[a[j]]=tmp.size()-1;
                 else{
                    while(tmp[tmp.size()-1]!=a[j]) lst[tmp[tmp.size()-1]]=-1,tmp.pop_back();
                 }
            }
            for(int j=1;j<=m;j++){
                if(lst[j]!=-1) res[j]+=cnt[i];
            }
        }
        for(int i=1;i<=m;i++) cout<<res[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
