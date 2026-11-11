#include<bits/stdc++.h>
using namespace std;
const int N=1e5*6+10;
int a[N];
bool b[N];
int c[N];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //1 3
   // if(n<=5 && m<=2){
        for(int st=1;st<=n;st++){
            memset(b,0,sizeof(b));
            stack<int> q;
            for(int i=st;i<=n;i++){
                if(!b[a[i]])
                {
                    q.push(a[i]);
                    b[a[i]]=1;
                }else
                {
                    while(q.top()!=a[i]){
                        b[q.top()]=0;
                        q.pop();
                    }
                    q.pop();
                    q.push(a[i]);
                }

            }
            while(!q.empty()){
                //cout<<q.top()<<' ';
                c[q.top()]++;
                q.pop();
            }
            //cout<<'\n';
        }

        for(int i=1;i<=m;i++){
            cout<<c[i]<<' ';
        }
   // }
    //else
   // {
   //     for(int i=1;i<=n;i++){
   //         c[i]=
   //     }
   // }



    return 0;
}
