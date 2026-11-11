#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],nowuse[N],isexist[N],end_exist[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(nowuse,0,sizeof(nowuse));
        memset(isexist,0,sizeof(isexist));
        int nownum=0;
        for(int j=i;j<=n;j++){
            if(!isexist[a[j]])nowuse[++nownum]=a[j],isexist[a[j]]=1;
            else{
                for(int k=1;k<=nownum;k++)if(nowuse[k]==a[j]){
                    int nownum_copy=nownum;
                    for(int h=k;h<=nownum_copy;h++)nowuse[h]=0,nownum--,isexist[a[h]]=0;
                    nowuse[++nownum]=a[j];
                    break;
                }
            }
        }
        for(int j=1;j<=nownum;j++)end_exist[nowuse[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<end_exist[i]<<' ';
    return 0;
}
