#include<bits/stdc++.h>
using namespace std;
struct node{
    long long x;
    char y;
};
node a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    long long ans=0;
    for(int i=1,j=n;i<j;){
            if(a[i].x<a[j].x){
                if(a[i].y!=a[j].y){
                    ans+=a[i].x;
                }
                a[j].x-=a[i].x;
                i++;
            }
            else if(a[i].x>a[j].x){
                if(a[i].y!=a[j].y){
                    ans+=a[j].x;
                }
                a[i].x-=a[j].x;
                j--;
            }
            else{
                if(a[i].y!=a[j].y){
                    ans+=a[j].x;
                }
                i++;
                j--;
            }
    }
    cout<<ans;
    return 0;
}
