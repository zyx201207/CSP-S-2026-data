#include<bits/stdc++.h>
#define num first
#define er second
using namespace std;
pair<int,string>a[200010];
queue<pair<int,string> >q;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int ms=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int x1=x;
        string t="";
        while(x1){
            t+=x1%2+'0';
            x1/=2;
        }
        a[i].num=x;
        a[i].er=t;
        int k=t.size();
        ms=max(ms,k);
    }
    int cnt;
    while(ms){
        cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i].er.size()>=ms&&a[i].er[ms]=='1'){
                cnt++;
                if(cnt==m){
                    break;
                }
            }
        }
        if(cnt==m){
            for(int i=1;i<=n;i++){
                if(a[i].er[ms]=='1'){
                    q.push({a[i].num,a[i].er});
                }
            }
            break;
        }

        ms--;
    }
    int ans=-1;
    while(ms){
        cnt=0;
        for(int i=1;i<=q.size();i++){
            if(q.front().er.size()>=ms&&q.front().er[ms]=='1'){
                cnt++;
                if(cnt==m){
                    break;
                }
            }
            q.push(q.front());
            q.pop();
        }
        if(cnt==m){
            int l=q.size();
            for(int i=1;i<=l;i++){
                if(q.size()==m){
                    while(q.size()){
                        if(ans==-1){
                            ans=q.front().num;
                        }else{
                            ans=(ans&q.front().num);
                        }
                        q.pop();
                    }
                    cout<<ans;
                    return 0;
                }
                if(q.front().er[ms]=='1'){
                    q.push({a[i].num,a[i].er});
                }
                q.pop();
            }
             if(q.size()==m){
                while(q.size()){
                    if(ans==-1){
                        ans=q.front().num;
                    }else{
                        ans=(ans&q.front().num);
                    }
                    q.pop();
                }
                cout<<ans;
                return 0;
            }
        }
        ms--;
    }
    while(m--){
        if(ans==-1)ans=q.front().num;
        else ans=(ans&q.front().num);
        q.pop();
    }
    cout<<ans;
    return 0;
}
