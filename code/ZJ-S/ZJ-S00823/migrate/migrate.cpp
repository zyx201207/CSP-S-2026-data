#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],ans;
long long co[2000005],dis[2000005],q[2000005];
long long bfs(long long pos){
    long long head=1,tail=1,now,add=0;
    for(int i=1;i<=n;i++){
    	dis[i]=INT_MAX;
    	co[i]=0;
	}
    q[tail++]=pos;
    dis[pos]=0;
    while(head<tail){
        now=q[head];
        head++;
        for(int i=now+1;i<=n;i++){
            if(x[i]-x[now]<=d){
                if(dis[i]==INT_MAX){
                    dis[i]=dis[now]+1;
                    co[i]++;
                    q[tail++]=i;
                }
                else if(dis[i]==dis[now]+1) co[i]++;
            }
            else break;
        }
    }
    for(int i=1;i<=n;i++){
        if(co[i]==2) add++;
    }
    return add;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d; 
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<n;i++)
			ans+=bfs(i);
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}
/*0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
