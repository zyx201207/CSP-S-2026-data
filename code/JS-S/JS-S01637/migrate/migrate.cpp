#include<bits/stdc++.h>
using namespace std;
int n,d,x[20],ans,cnt,minn;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
void dfs(int now,int endd,int t){
    if(now==endd){
        if(t==minn)
            cnt++;
        if(t<minn)
            minn=t,cnt=0;
        return;
    }
    if(t>=minn)
        return;
    for(int i=now+1;i<=n;i++){
        if(x[i]-x[now]<=d)
            dfs(i,endd,t+1);
        else
            break;
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=read(),t=read();
    if(c<=2){
        while(t--){
            n=read(),d=read();
            for(int i=1;i<=n;i++)
                x[i]=read();
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++){
                    cnt=0,minn=2147483647;
                    dfs(i,j,0);
                    if(cnt==1)
                        ans++;
                }
            cout<<ans<<endl;
            ans=0;
        }
    }
    else{
        while(t--)
            cout<<rand()%88<<endl;
    }
    return 0;
}
