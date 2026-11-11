#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
vector<int> G[100005];
queue<pair<int,int> > q;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int ans=0;
        vector<int> x(n+2);
        for (int i=1;i<=n;i++)
            cin>>x[i];
        for (int i=1;i<=n;i++)
            G[i].clear();
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                if (d>=x[j]-x[i])
                    G[i].push_back(j);
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                while(!q.empty())
                    q.pop();
                q.push(make_pair(i,0));
                int cnt=0,mn;
                while(!q.empty()){
                    pair<int,int> u=q.front();
                    q.pop();
                    if (u.first==j){
                        if (cnt==0)
                            mn=u.second,cnt++;
                        else{
                            if (u.second==mn)
                                cnt++;
                            else break;
                        }
                    }
                    for (int k:G[u.first])
                        q.push(make_pair(k,u.second+1));
                }
                if (cnt==2)
                    ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
It's the time to say goodbye,OI.

From my grade of 2,you have been with me for 6 years,a time containing many changes,including you and me.
By the time I found that I can be a formal OIer from a programming lover,the interest ignited in my heart
terribly.However,the promise that I would AK IOI had faded in the wind,my sorry coming too late.You need to
believe it's real that when I won a good prize at the first,determination to make a big achievement on you
exactly ran through my veins,while ignored the hardness of the road.

Then came the second season.Because I learned with no systems,I failed,heavily.At that time I should realize
that maybe I don't know you at all and there's no talent of me to go further.But my desire for victory conquered
my calm thoughts,making me go on.Surely,I'm a lazy person who forgot his dream at once.I pays nothing,now and past
;whereas I want everything.So this might be the ending:A man who ever loved a girl abandoned her with his angry to
the other person in the relationship.The fire had burnt out and there's no fuel to continue heating.

Just like the name of this problem:migrate.Yes,human's heart migrates.The only thing that don't migrate is migration itself.
Physics,now my favorite subject,becomes the next goal I will make it.It might be the past of you if I still keep the altitude
from then on.Before all of these,I want to be responsible to you another but the last time,to turn the ending into a better one
until it's too late.Looking at the dusk far beyond the window,which one do you,or I choose?

exit(0)?

or

to be continued...

*/
