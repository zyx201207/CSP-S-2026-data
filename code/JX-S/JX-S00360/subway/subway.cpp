#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y;
long long w[500005];
long long ans[2005][2005],dph=0;
struct node{
    int point_to,time;
}tmp1;
vector<node> mp[2005];
void func(int point_from,int point_now,long long time_now){
//    cout<<endl;
//    dph++;
//    for(int i=0;i<=dph;i++) cout<<"  ";
//    cout<<"now:"<<point_now<<" time:"<<time_now;
    ans[point_from][point_now]=time_now;
    ans[point_now][point_from]=time_now;
    int len=mp[point_now].size();
    for(int i=0;i<len;i++){
        if(mp[point_now][i].point_to==point_now||point_from==mp[point_now][i].point_to) continue;
        if(time_now+mp[point_now][i].time<ans[point_from][mp[point_now][i].point_to]||ans[point_from][mp[point_now][i].point_to]==0){
            func(point_from,mp[point_now][i].point_to,time_now+mp[point_now][i].time);
        }
    }
//    dph--;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    if(c<=11){
        int t,a,k;
        for(int i=1;i<=n;i++){
            cin>>t;
            for(int j=1;j<=t;j++){
                cin>>a>>k;
                tmp1.point_to=a,tmp1.time=k;
                mp[i+m].push_back(tmp1);
                tmp1.point_to=i+m;
                mp[a].push_back(tmp1);
            }
        }
        for(int i=1;i<=m;i++){
    //        cout<<endl<<"now start:"<<i<<endl;
            func(i,i,0);
        }
    //    cout<<endl;
        for(int i=0;i<q;i++){
            cin>>x>>y;
            cout<<ans[x][y]+w[x]+w[y]<<endl;
        }
    }
    return 0;
}
