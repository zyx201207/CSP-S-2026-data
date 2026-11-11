#include<iostream>
#include<stack>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int tong[300005]={};
    int cnt[300005];
    stack<int>s;
    int n,m,a[500005]={};
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++)tong[j]=0;
        for(int j=i;j<n;j++){
            if(tong[a[j]]==0){
                s.push(a[j]);
                tong[a[j]]++;
            }
            else{
                while(tong[a[j]]!=0){
                    tong[s.top()]--;
                    s.pop();
                }
                s.push(a[j]);
                tong[a[j]]++;
            }
        }
        for(int j=1;j<=m;j++){
            if(tong[j]==1)cnt[j]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
