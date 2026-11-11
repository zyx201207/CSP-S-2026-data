#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m;
    cin>>n>>m;
    int a[n+5],f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sum[m+5]={0};
    for(int i=1;i<=n;i++){
        int visited[m+5]={0},stage[n+5]={0};
        for(int j=i;j<=n;j++){
            if(visited[a[j]]==0){
                sum[a[j]]++;
                stage[f]=a[j];
                f++;
                visited[a[j]]=1;
            }
            else{
                int g=0;
                for(int k=1;k<f;k++){
                    if(stage[k]==a[j]) g=1;
                    if(g==1){
                        sum[stage[k]]--;
                        visited[stage[k]]=0;
                        stage[k]=0;
                    }
                }
                sum[a[j]]++;
                visited[a[j]]=1;
                f=1;
        }
    }
}
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
