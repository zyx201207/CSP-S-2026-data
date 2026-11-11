#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define F1 freopen("and.in","r",stdin)
#define F2 freopen("and.out","w",stdout)
void io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int n,m,a[200000+100],ans=-1,num,cnum[31];
bool s[31][200000+100];
bool choose[200000+100];
void cnt(int x,int i){
    int res=0;
    while(res<31){
        if(x&1){
            s[res][i]=true;
            cnum[res]++;
        }
        x>>=1;
        res++;
    }
}
int main(){
    F1;F2;
    io();
    memset(choose,true,sizeof(choose));
    cin>>n>>m;
    num=n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cnt(a[i],i);
    }
    for(int now=30;now>=0&&num>=m;now--){
        if(cnum[now]>=m){
            for(int i=1;i<=n;i++){
                if(s[now][i]==false){
                    choose[i]=s[now][i];
                    for(int j=30;j>=0;j--){
                        if(s[j][i]){
                            cnum[j]--;
                            s[j][i]=false;
                        }

                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!choose[i])continue;
        if(ans==-1)ans=a[i];
        else ans&=a[i];
    }
    cout<<ans;
    return 0;
}
