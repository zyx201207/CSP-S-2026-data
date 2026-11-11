#include<bits/stdc++.h>
using namespace std;
long long n,c,m,d,q;
long long w[500005];
long long ans[2010][2010],dp=0;
vector<int> mp[2010];
int x=0,y=0;
void func(int point_from,int point_now,int point_to,int time,long long time_now){
    //cout<<point_now<<endl;
    cout<<endl;
    dp++;
    /*for(int i<=dp;i++){
        cout<<" ";
    }*/
    ans[point_from][point_now]=time_now;
    ans[point_now][point_from]=time_now;
    int len=mp[point_now].size();
    for(int i=1;i<=len;i++){
        if(mp[point_now][i].point_to=point_now||point_from==mp[point_now][i].point_to)continue;
        if(time_now+mp[point_now][i].time<ans[point_from]mp[point_now][i].point_to){
            func[point_from],mp[point_now][i].point_to,time_now+mp[point_now][i].time;
        }
    }
    dp--;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    if(c<=11){
        int t,k,a;
        for(int i=1;i<=n;i++){
            cin>>t;
            for(int j=1;j<=t;j++){
                cin>>a>>k;
                tmp1.point_to=a;
                mp[i+m].push_back(tmp1);
                mp[a],push_back(tmp1);
            }
        }
        for(int i=0;i<m;i++){
            func(i,i,0);
        }
        for(int i=0;i<q;){
            cin>>x>>y;
            cout<<ans[x][y]+w[x][y]+w[y]<<endl;
        }
    }
    return 0;
}
