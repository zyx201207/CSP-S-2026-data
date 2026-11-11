#include<bits/stdc++.h>
using namespace std;
const int MAXN=1442;
int deg[MAXN],cop[MAXN];
struct edge_node{
    int to;
    int next;
}edge[MAXN*3+6042];
int tot=0,head[MAXN*2+6042];
struct node{
    int pos;
    int deg;
}point[MAXN];
void add(int tempx,int tempy){
    edge[++tot].to=tempy;
    edge[tot].next=head[tempx];
    head[tempx]=tot;
}
bool cmp(node temp1,node temp2){
    return temp1.deg>temp2.deg;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        for(int i=1;i<=1024;i++)point[i].pos=point[i].deg=cop[i]=0;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int tempx,tempy;
            cin>>tempx>>tempy;
            add(tempx,tempy);
            cop[tempx]++;cop[tempy]++;
            point[tempx].pos=tempx;
            point[tempy].pos=tempy;
            point[tempx].deg++;
            point[tempy].deg++;
        }
        if(k==2)cout<<1<<endl;
        else{
            sort(point+1,point+n+1,cmp);
            if(point[1].deg+point[2].deg+2>=k)cout<<2<<endl;
            else{
                int sum=0;
                for(int i=head[point[1].pos];i;i=edge[i].next)sum+=cop[edge[i].to];
                for(int i=head[point[2].pos];i;i=edge[i].next)sum+=cop[edge[i].to];
                if(sum+point[1].deg+point[2].deg+2>=k)cout<<3<<endl;
                else cout<<4<<endl;
            }
        }
    }
    return 0;
}
