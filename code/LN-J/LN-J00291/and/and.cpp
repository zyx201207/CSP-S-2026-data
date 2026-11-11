#include<iostream>
using namespace std;
const int N=1e5+10;
#define int long long
int a[N];
void init(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int n,m;
    cin>>n>>m;
    int max1=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>max1){
            max1=a[i];
        }
    }
    if(m==1){
        cout<<max1;
        return 0;
    }
    if(m==n){
        int cnt=a[0];
        for(int i=1;i<n;i++){
            cnt&=a[0];
        }
        cout<<cnt;
        return 0;
    }
    int maxx=0;
    if(m==2||m>3){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((a[i]&a[j])>maxx){
                    maxx=(a[i]&a[j]);
                }
            }
        }
    }
    if(m==3){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if((a[i]&a[j]&a[k])>maxx){
                        maxx=(a[i]&a[j]&a[k]);
                    }
                }
            }
        }
    }
    cout<<maxx;
    return 0;
}
