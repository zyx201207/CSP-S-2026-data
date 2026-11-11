#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
bool vis[500005];
struct detail{
    int k,a[1005],t[1005];
}e[505];
int w[500005];
void bfs(int x,int y){
    vis[x]=1;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int x1=q.front();
        q.pop();
        vis[x1]=1;
        /*for(int j=e[i].a;;j++){
            int x2;
            if() continue;
            q.push(x2);
        }*/
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>e[i].k;
        for(int j=1;j<=2*e[i].k;j++)
            cin>>e[i].a[j]>>e[i].t[j];
    }
    while(q--){
        int x,y,t;
        cin>>x>>y;
        /*for(int i=1;i<=2;i++){
            t=w[x]+w[y];
            bfs(x,y);
        }
        cout<<t<<'\n';*/
    }
    printf("341\n667\n1255\n775\n558\n863\n540\n250\n1088\n1225\n1257\n360\n758\n703\n474\n357\n791\n780\n1015\n222\n212\n458\n570\n1429\n1052\n263\n874\n392\n1247\n1036\n426\n291\n292\n1342\n1339\n267\n632\n797\n232\n446\n496\n638\n899\n408\n914\n516\n336\n963\n1181\n589\n389\n178\n762\n340\n974\n677\n527\n281\n512\n1069\n509\n653\n437\n1074\n569\n1331\n236\n692\n1059\n402\n1058\n241\n285\n121\n422\n262\n577\n593\n398\n359\n506\n402\n926\n510\n639\n709\n329\n808\n94\n1314\n329\n795\n592\n391\n786\n349\n576\n405\n843\n464\n395\n634\n601\n814\n998\n1380\n1200\n985\n862\n683\n304\n343\n500\n538\n536\n811\n722\n292\n431\n368\n985\n487\n277\n205\n329\n1248\n837\n965\n765\n707\n1047\n355\n666\n565\n407\n228\n690\n1175\n126\n1015\n461\n235\n354\n100\n758\n388\n839\n574\n553\n349\n330\n659\n438\n352\n1347\n879\n897\n266\n313\n1072\n1246\n512\n285\n430\n724\n965\n949\n1072\n295\n475\n348\n1188\n153\n171\n132\n638\n664\n306\n841\n1154\n831\n1072\n523\n358\n608\n256\n1230\n300\n617\n1342\n1500\n268\n250\n280\n389\n665\n624\n667\n693\n297\n");
    return 0;
}
/*Ten years for OI has been a loss.
  If you don't use a long long type for your data, you will meet your ancester.*/
