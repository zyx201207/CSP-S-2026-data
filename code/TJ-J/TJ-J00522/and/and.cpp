#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n,m;
int a[200005];
vector<int> v[200005];
int maxx,maxcnt;
int ans;
bool flag[200005];

void dfs(int x,int y,int cnt){
    if(cnt==m){
        ans=max(ans,y);
        return;
    }
    if(x==n+1){
        return;
    }
    if(y==-1){
        dfs(x+1,a[x],cnt+1);
    }else{
        dfs(x+1,y&a[x],cnt+1);
    }
    dfs(x+1,y,cnt);
}

int f(int i){
    int x=a[i];
    int cnt=0;
    while(x){
        v[i].push_back(x%2);
        x/=2;
        cnt++;
    }
    return cnt;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        maxcnt=max(maxcnt,f(i));
    }
    if(m==1){
        cout << maxx;
    }else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout << ans;
    }else if(m<=20){
        dfs(1,-1,0);
        cout << ans;
    }else{
        bool f=true;
        for(int i=maxcnt-1;i>=0;i--){
            int cnt=0;
            vector<int> temp,temp1;
            for(int j=1;j<=n;j++){
                if(v[j].size()>=i+1&&!flag[j]&&v[j][i]==1){
                    cnt++;
                    temp.push_back(j);
                }else{
                    temp1.push_back(j);
                }
            }
            if(cnt>m){
                for(int x:temp1){
                    flag[x]=true;
                }
            }else if(cnt==m){
                ans=a[temp[0]];
                for(int x:temp){
                    ans&=a[x];
                }
                f=false;
                cout << ans;
                break;
            }
        }
            if(f){
                int cnt=0;
                ans=-1;
                for(int i=1;i<=n;i++){
                    if(!flag[i]){
                        cnt++;
                        if(ans==-1){
                            ans=a[i];
                        }else{
                            ans&=a[i];
                        }
                        if(cnt==m){
                            break;
                        }
                    }
                }
                cout << ans;
            }
    }
    return 0;
}
