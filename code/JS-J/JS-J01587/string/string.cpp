#include<iostream>
using namespace std;
const int N=2e5+5;
long long List[N];char t[N];
int min(int a,int b){
    if(a<b){return a;}
    else{return b;}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,temp;long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>List[i];
        cin>>t[i];
    }
    int l=1,r=n;
    while(l<r){
        int mi=min(List[l],List[r]);
        if(t[l]!=t[r]){
            ans+=mi;
        }
        List[l]-=mi;
        List[r]-=mi;
        if(List[l]==0){
            l++;
        }if(List[r]==0){
            r--;
        }
    }
    cout<<ans;
    return 0;
}
