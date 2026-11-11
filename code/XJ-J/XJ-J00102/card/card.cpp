#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=500005,MAXM=300005;
int arr[MAXN],M[MAXM],res[MAXM]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool Aflag=1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        --arr[i];
        if(i>0&&arr[i]<arr[i-1]) Aflag=0;
    }
    if(Aflag){
        for(int i=0;i<n;i++) if(i==n-1||arr[i]<arr[i+1]) cout<<(i+1)<<' ';
        cout<<'\n';
        return 0;
    }
    for(int j=0;j<m;j++) M[j]=-1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(M[arr[j]]!=-1) for(int k=M[arr[j]]+1;k<j;k++) M[arr[k]]=-1;
            M[arr[j]]=j;
        }
        for(int j=0;j<m;j++) if(M[j]!=-1){
            ++res[j];
            M[j]=-1;
        }
    }
    for(int i=0;i<m;i++) cout<<res[i]<<' ';
    cout<<'\n';
    return 0;
}