#include<bits/stdc++.h>
#define int long long

using namespace std;
int a,b;
string p,q;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>a>>p>>b>>q;
    cout<<(int)(a==b);
    cout<<(int)((a==b)&&(p[0]==q[0]&&p[1]==q[1]));
    cout<<(int)((a==b)&&((p[0]==q[0]&&p[1]==q[1])&&((p.find('A')!=-1)&&(q.find('B')!=-1||q.find('C')!=-1)||(p.find('B')!=-1)&&(q.find('A')!=-1)||(p.find('C')!=-1)&&(q.find('B')!=-1||q.find('A')!=-1)||(p.find('F')!=-1)&&(q.find('E')!=-1)||(p.find('E')!=-1)&&(q.find('F')!=-1))));
    cout<<(int)((a==b)&&((p[0]==q[0]&&p[1]==q[1])&&(((p.find('A')!=-1)&&(q.find('B')!=-1))||(p.find('B')!=-1)&&(q.find('A')!=-1||q.find('C')!=-1)||(p.find('C')!=-1)&&(q.find('B')!=-1)||(p.find('F')!=-1)&&(q.find('E')!=-1)||(p.find('E')!=-1)&&(q.find('F')!=-1))));

    return 0;

}
