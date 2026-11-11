#include <bits/stdc++.h>

using namespace std;
map<int,list<bool>> a;
list<bool> p;
    bool q[32];
void zh(long long k){
    if(k<=1){
        p.push_front(k);
        return ;
    }
    p.push_front(k%2);
    zh(k/2);
}
int main()
{
 //   freopen("and.txt","r",stdin);
     freopen("and.in","r",stdin);
     freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long a1;
        cin>>a1;
        p.clear();
        zh(a1);
        int k=31-p.size()+1;
        for(int j=1;j<=31-p.size();j++){
            a[j].push_back(0);
        }
        for(auto j:p){
            a[k].push_back(j);
            k++;
        }
    }
    while(a.size()>m){
        for(int i=1;i<=31;i++){
                if(a.size()==m){
                    break;
                }
            for(auto j:a[i]){
                if(a.size()==m){
                    break;
                }
                if(!j && a.size()>m){
                    a.erase(i);
                }
            }
        }
    }
    for(int i=1;i<=31;i++){
        for(auto j:a[i]){
            q[i]=q[i]&j;
        }
    }
    int ans=0,gh=30;
    for(int i=1;i<=31;i++){
        ans+=q[i]*(1<<gh);
        gh--;
    }
    cout<<ans;
    return 0;
}
