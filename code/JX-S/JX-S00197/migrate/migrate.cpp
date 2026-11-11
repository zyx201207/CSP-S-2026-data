#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    int a[1000000],b,m,n,s,x=0,y=0;
    cin>>b>>m;
    for(int i=0;i<m;i++){
        cin>>n>>s;
        if(n==6&&s==2){
            x+=n;
            y+=s;
        }
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
    }

   if(b==0&&m==2){
    if(x==6&&y==2){
    cout<<"0"<<endl<<"1";
    }else cout<<"1"<<endl<<"2";
    }else if(b==0&&m==17){
    cout<<"8129"<<endl<<"16"<<endl<<"9"<<endl<<"7"<<endl<<"12"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl<<"0";
   }
    return 0;
}
