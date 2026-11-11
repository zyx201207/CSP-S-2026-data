#include<bits/stdc++.h>
using namespace std;
const int N=5000010;
const int M=3000010;
int n,m,a[N],t[N],v[N],ans[M],noww=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    //cout<<n<<" "<<m;
    for(int i=1;i<=n;i++) cin>>a[i];
    //for(int i=1;i<=4;i++) cout<<a[i]<<" ";
    for(int i=1;i<=n;i++){
        noww=1;
        for(int j=i;j<=n;j++){
            if(v[a[j]]!=0){
                int l=noww;
                noww=v[a[j]];
                for(int k=noww;k<=l;k++) v[k]=0;
            }
            v[a[j]]=noww;
            t[noww]=a[j];
            //cout<<t[noww];
            noww++;

        }
        //for(int j=1;j<=noww;j++) cout<<t[j]<<" ";
        for(int j=1;j<noww;j++){
                //cout<<t[j]<<" ";
                ans[t[j]]++;
                v[t[j]]=0;
        }
        //cout<<endl;
    }
    for(int i=1;i<m;i++){
        cout<<ans[i]<<" ";
    }
    cout<<ans[m];
    //cout<<"3 1 4";
    return 0;
}
