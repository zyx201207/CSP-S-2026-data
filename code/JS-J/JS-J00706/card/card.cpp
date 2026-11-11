#include<bits/stdc++.h>
using namespace std;
int last_r[300005],queue_f[500005],ans[300005];
int read(){
    char c;
    int ans=0;
    do{
        c=getchar();
        if(c==' ')break;
        if(c<'0'||c>'9')break;
        ans=ans*10+int(c-'0');
    }while(1);
    return ans;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++){
       cin>>a[i];
    }
    int l=1,r;
    for(int i=1;i<=n;i++){
            l=i;
            r=i-1;
        for(int j=i;j<=n;j++){
            if(last_r[a[j]]==0){
                r++;
                queue_f[r]=a[j];
                last_r[a[j]]=r;
            }else{
                for(int f=r;f>=last_r[a[j]]+1;f--){
                    last_r[queue_f[f]]=0;
                }

                r=last_r[a[j]];

                queue_f[r]=a[j];
            }

           /*     cout<<"t "<<j-i+1<<":";
           for(int k=l;k<=r;k++){
               cout<<queue_f[k]<<" ";
           }

           cout<<endl;
           cout<<"r "<<j-i+1<<":";
           for(int k=1;k<=20;k++){
               cout<<last_r[k]<<" ";
           }

           cout<<endl;*/
        }
        for(int k=i;k<=r;k++){
                ans[queue_f[k]]++;
        }
        memset(queue_f,0,sizeof(queue_f));
            memset(last_r,0,sizeof(last_r));
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }

    return 0;
}
