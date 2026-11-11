/*
特殊性质 A：每条线路至多经过 2 个地铁站，即对于所有 i (1 ≤ i ≤ n)，
           均有 k i ≤ 2。
特殊性质 B：对于所有线路经过的所有地铁站，从站厅走到对应线路站台的步行时
           间都相同，即存在正整数 T，使得对于所有 i,j (1 ≤ i ≤ n, 
           1 ≤ j ≤ k i )，均有 t i,j = T。
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,q,d;
int w[500005];
vector<int> aa[500005];
bool isb=true;
int disk[500005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    
    cin>>c>>n>>m>>d>>q;
    int a[n+5][m+5],t[n+5][m+5];
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
            aa[j].push_back(i);
//            cout<<i<<" "<<aa[j].head()<<" ";
            if(t[i][j]!=t[i][j-1] && j>=2) isb=false;
        }
//        cout<<"\n";
//        for(int j=1;j<=k;j++){
//	        for(int h=0;h<3;h++)
//	            cout<<aa[j][h]<<" ";
	        // cout<<"\n";
//    	}
    }

//    cout<<aa[1].size()<<endl;
    // cout<<"while\n";
    while(q--){
        int x,y;
        cin>>x>>y;
        // cout<<"x,y: "<<x<<" "<<y<<"\n";
        if(isb==true){
            int xx[aa[x].size()],yy[aa[y].size()];
		    for(int i=1;i<=aa[x].size();i++){ xx[i]=aa[x][i-1]; /*cout<<xx[i]<<" ";*/}
            // cout<<"\n";
		    for(int i=1;i<=aa[y].size();i++){ yy[i]=aa[y][i-1]; /*cout<<yy[i]<<" ";*/}
            // cout<<"\n";
		    int lx=1,ly=1;
		    sort(xx,xx+aa[x].size()+1);
		    sort(yy,yy+aa[y].size()+1);
            cout<<w[x]+w[y]+t[1][1]*2<<"\n";
		    // while(lx<=aa[x].size() && ly<=aa[y].size()){
		    //     if(xx[lx]=yy[ly]){
		    //         // cout<<w[xx[lx]]+t[xx[lx]][x]+t[yy[ly]][y]+w[yy[ly]]<<"\n"; 
            //         cout<<"chonghe\n";
            //         break;
            //     }
            //     if(xx[lx]<yy[ly]) lx++;
            //     if(xx[lx]>yy[ly]) ly++;
		    // }
            // if(lx>aa[x].size() || ly>aa[y].size()) cout<<"none chonghe\n";
        }
    }
    return 0;
}

/*
// no!! i can not do it

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,q,d;
int w[500005];
struct Subway{
    int a,t;
};
bool isb=true;
int dob()
{

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    
    cin>>c>>n>>m>>d>>q;
    Subway sub[n+5];
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>sub[j].a>>sub[j].t;
            if(sub[j].t!=sub[j-1].t && j>=2) isb=false;
        }
    }
    if(isb==true){
        dob();
    }
    while(q--){
        int x,y;
        cin>>x>>y;
    }
    return 0;
}

*/
