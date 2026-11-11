#include<bits/stdc++.h>
using namespace std;
int ipo,n,m,d,q,c,f,e,l,r;
int tot,head[8000005],Next[8000005],ver[8000005],edge[8000005],dist[8000005];
long long op[8000005];
void add(int x,int y,int z){
    tot++;ver[tot]=y;edge[tot]=z;Next[tot]=head[x];head[x]=tot;
}
priority_queue <pair<int,int> > disj;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>ipo>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>c;
        add(i+m,i,c);
        add(i,i+m,c);
        //cout<<i<<" "<<i+m<<" "<<c<<"\n";
    }
    for(int i=1;i<=n;i++){
        cin>>c;
        for(int j=1;j<=c;j++){
            cin>>f>>e;
            add(2*m+i,f+m,e);
            add(f+m,2*m+i,e);
            //cout<<2*m+i<<" "<<f+m<<" "<<e<<"\n";
        }
    }
    for(int i=1;i<=q;i++){
        cin>>l>>r;
        memset(dist,0,sizeof(dist));
        memset(op,0x3f,sizeof(op));
        disj.push(make_pair(0,l));
        op[l]=0;
        while(disj.size()){
            int x=disj.top().second;
            disj.pop();
            for(int i=head[x];i;i=Next[i]){
                int y=ver[i],z=edge[i];
                if(op[y]>op[x]+z){
                    op[y]=op[x]+z;
                    //cout<<x<<" "<<y<<" "<<op[x]<<" "<<op[y]<<" "<<edge[i]<<"\n";
                    disj.push(make_pair(-op[y],y));
                }
            }
        }
        cout<<op[r]<<"\n";
    }
    return 0;
}
