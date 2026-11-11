#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int N=6e5;
int n,m,a[N],flag[N],q[N],ans[N],l;
void in(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
}
void print(){

    return ;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   in();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int t=0;
    while(t<=n){
        for(int i=0;i<=N;i++){
            q[i]=0;
            flag[i]=0;
        }
        l=0;
        t++;
        for(int i=t;i<=n;i++){
            if(!flag[a[i]]){
                l++;
                flag[a[i]]=l;
                q[l]=a[i];
        //print();
            }
            else{
                int te=flag[a[i]]-1;
                for(int j=flag[a[i]];j<=l;j++){
                    flag[q[j]]=0;
                    q[j]=0;
                }
//print();
                l=te;
                l++;
                flag[a[i]]=l;
                q[l]=a[i];
//print();
            }

        }
        for(int i=1;i<=m;i++){
            if(flag[i]){
                ans[i]++;
               // cout<<t<<" "<<i<<"\n";
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
