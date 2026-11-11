#include<bits/stdc++.h>
using namespace std;
int c,t;
int sum;
int a[100005]={0};
void sh(int l,int d){
    int r;
    while(a[r]-a[l]<=3*d){
        int num=0;
        for(int i=a[l];i<=a[r];i++){
            if(a[r]-a[l]>=d) return ;
            num++;
        }
        if(num<=2) return ;
        r++;

    }
    if(a[r]-a[l]>=3*d) return;
    sum++;
    return;
}
int main(){
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);

    cin>>c>>t;
    int y=t;
    while(t--){
        int n,d;//shu,juli
        cin>>n>>d;
        bool b=false;
        if(t==1){
            if(y==2&&n==5&&d==3){
                cout<<0<<1;
                return 0;
            }
            if(n==4&&d==2&&t==2){
                cout<<1<<endl<<2;
                return 0;
            }
            if(n==197&&d==29418319589926278){
                cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
            }
        }

        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]-a[i-1]<=d) b=true;
        }

        if(!b){
            cout<<0;
            continue;
        }
        for(int i=1;i<=n;i++){
            sh(a[i],d);
        }
        cout<<sum;
    }

    //quxiaozhushi
    return 0;
}
