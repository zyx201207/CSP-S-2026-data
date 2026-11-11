#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m,b[300100],g;
queue<int> q;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    g=n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    for(int i=1;i<=n;i++){
        int d[300100];
        vector<int> c;
        int j=1;
        while(j<=g){
            int x=q.front();
            c.push_back(x);
            q.pop();
            q.push(x);
            d[x]++;
            if(d[x]>1){
                for(int i=0;i<c.size()-1;i++){
                    if(c[i]==x){
                        for(int j=i;j<c.size()-1;j++){
                            c[j]=0;
                        }
                        break;
                    }
                }
            }
            j++;
        }
        for(int i=0;i<c.size();i++){
            if(c[i]!=0){
                b[c[i]]++;
            }
        }
        q.pop();
        g--;
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
