#include<iostream>
#include<cmath>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005];
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    if(n==m){
        int s=a[0];
        for(int i=1;i<n;i++)s=s&a[i];
        cout<<s;
    }
    else if(m==n-1){
        int maxs=-1;
        for(int i=0;i<n;i++){
            int s=-1;
            for(int j=1;j<n;j++){
                if(j==i)continue;
                if(s==-1)s=a[0];
                else s=s&a[i];
            }
            maxs=max(maxs,s);
        }
        cout<<maxs;
    }
    else if(m==1){
        int maxs=-1;
        for(int i=0;i<n;i++)maxs=max(maxs,a[i]);
        cout<<maxs;
    }
    else if(m==2){
        int maxs=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int s;
                if(i==j)s=a[i];
                else s=a[i]&a[j];
                maxs=max(maxs,s);
            }
        }
        cout<<maxs;
    }
    return 0;
}
