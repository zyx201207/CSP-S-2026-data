
#include<iostream>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
//cout<<a[3]<<" ";
    int cou[m+1];
    for(int i=1;i<=m;i++){
        cou[i]=0;
    }
    for(int i=1;i<=n;i++){
        int s[n+1],s1=0;
        int x[m+1];
        for(int j=0;j<=m;j++){
            x[j]=0;
        }
        for(int j=i;j<=n;j++){
            if(x[a[j]]==0){
                s[s1++]=a[j];x[a[j]]=1;}
            else if(x[a[j]]){
                for(int k=s1-1;s[k]!=a[j]&&k!=-1;k--){
                    s1--;
                    x[s[k]]--;
                }
                s1--;
                s[s1++]=a[j];


            }
            //x[a[j]]=1;
        }
        for(int j=1;j<=m;j++){
            if(x[j]){
                cou[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cou[i]<<" ";
    }
    return 0;
}
