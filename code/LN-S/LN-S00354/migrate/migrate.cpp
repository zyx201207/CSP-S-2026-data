#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,s=1,dst;
int ac[2000001];
int roads(int a,int b,int deep){
    if(dst!=-1 && deep>dst){
        s-=1;
        return 0;
    }
    if(a+1==b){
        dst=deep;
        return 0;
    }
    if(max(ac[a],ac[b])-min(ac[a],ac[b])<=d){
        dst=deep;
        return 0;
    }
    s+=1;

    roads(a+1,b,deep+1);
    int f=a+2;
    while(1){
        if(max(ac[a],ac[f])-min(ac[a],ac[f])>d){
            f--;
            break;
        }else if(f+1>b){
            break;
        }else{
            f++;
        }
    }
    if(f!=a+1){
        roads(f,b,deep+1);
    }
    return 0;

}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int asd=t;asd>=1;asd--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>ac[i];
        }
        int sum=0;

        for(int i=n;i>=4;i--){
            for(int j=i-3;j>=1;j--){
                dst=-1;
                s=1;
                roads(j,i,1);
                if(s==2){
                    sum++;
                }
            }
        }
        sum+=0;
        cout<<sum<<endl;
    }
    return 0;
}
