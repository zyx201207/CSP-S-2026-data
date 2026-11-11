#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int d[N];
int q[N];
int pos=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(q,0,sizeof(q));
        for(int j=i;j<=n;j++){
            bool f=true;
            for(int k=1;k<=pos;k++){
                if(q[k]==a[j]){
                    f=false;
                }
            }
            if(f){
                q[pos++]=a[j];
            }else{
                while(q[pos]!=a[j]){
                    q[pos]=0;
                    pos--;
                }
            }

        }
        for(int j=1;j<=pos;j++){
            //if(q[j]==0)continue;
            d[q[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}
