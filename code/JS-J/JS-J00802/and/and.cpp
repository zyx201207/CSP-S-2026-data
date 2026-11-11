#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>=y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int maxx=1e5;
    int a[maxx]={0},ans[maxx]={0};
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(m==1){cout<<a[1];return 0;}
    int ia[maxx]={0};
    int w=0;
    while(a[1]>0){
        w++;
        ia[w]=a[1]%2;
        a[1]/=2;
    }
    for(int j=w;j>=(w/2);j--){
        swap(ia[w-j+1],ia[j]);
    }
    int ib[maxx]={0};
    int e=0;
    while(a[2]>0){
        e++;
        ib[e]=a[2]%2;
        a[2]/=2;
    }
    for(int j=e;j>=(e/2);j--){
        swap(ib[e-j+1],ib[j]);
    }
    int turn=0;
    if(e>w){
        for(int i=e;i>=1;i--){
            swap(ia[i],ia[i+e-w]);
        }
    }else if(w>e){
        for(int i=w;i>=1;i--){
            swap(ib[i],ib[i+w-e]);
        }
    }
    turn=max(e,w);
    for(long long i=1;i<=turn;i++){
        if(ia[i]==1&&ib[i]==1)
            ans[i]=1;
    }
    if(m==2){
        for(int i=turn;i>=1;i--){
            if(ans[i])
               sum+=pow(2,i-1);
        }
        cout<<sum;
        return 0;
    }else{
        for(int i=3;i<=m;i++){
            int ic[maxx]={0};
            w=0;
            while(a[i]>0){
                w++;
                ic[w]=a[i]%2;
                a[i]/=2;
            }
            for(int j=w;j>=(w/2);j--){
                swap(ic[w-j+1],ic[j]);
            }
            if(turn>w){
                for(int i=w;i>=1;i--){
                    swap(ic[i],ic[i+turn-w]);
                }
            }else if(w>turn){
                for(int i=w;i>=1;i--){
                    swap(ic[i],ic[i+w-turn-n]);
                }
            }
            turn=max(turn,w);
            for(int i=1;i<=turn;i++){
                if(ans[i]==1&&ic[i]==1)
                    ans[i]=1;
            }
        }
    }
    sum=0;
    for(int i=turn;i>=1;i--){
        if(ans[i])
            sum+=pow(2,i-1);
    }
    cout<<sum;
    return 0;
}
