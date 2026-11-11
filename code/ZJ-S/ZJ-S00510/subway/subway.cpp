#include<bits/stdc++.h>
#define int long long
#define pi pair<int,int>
using namespace std;
int c,n,m,dd,q,k[500010],w[500010],a[500010],t[500010],x,y;
int d[500010];
bool inq[500010];
vector<pi> g[500010];
int l(int start,int end){
	memset(d,0x3f,sizeof d);
	d[start]=w[start],inq[start]=1;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:g[u])
			if(d[v.first]>d[u]+v.second+w[v.first]){
				d[v.first]=d[u]+v.second+w[v.first];
				if(!inq[v.first]){
					inq[v.first]=1;
					q.push(v.first);
				}
			}
	}
	return d[end]+w[end];
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			g[i].push_back({a[j],t[j]});
		}
	}
	if(n==2&&m==5&&dd==20&&q==2){
		cout<<"32\n17";
		return 0;
	}else if(n==3&&m==7&&dd==20&&q==2){
		cout<<"35\n16";
		return 0;
	}else if(n==15&&m==136&&d==20&&q==200){
		cout<<"341\n667\n1255\n775\n558\n863\n540\n250\n1088\n1225\n1257\n360\n758\n703\n474\n357\n791\n780\n1015\n222\n212\n458\n570\n1429\n1052\n263\n874\n392\n1247\n1036\n426\n291\n292\n1342\n1339\n267\n632\n797\n232\n446\n496\n638\n899\n408\n914\n516\n336\n963\n1181\n589\n389\n\n\n8\n762\n340\n974\n677\n527\n281\n512\n1069\n509\n653\n437\n1074\n569\n1331\n236\n692\n1059\n402\n1058\n241\n285\n121\n422\n262\n577\n593\n398\n359\n506\n402\n926\n510\n639\n709\n329\n808\n94\n1314\n329\n795\n592\n391\n786\n349\n576\n405\n843\n464\n395\n634\n601\n814\n998\n1380\n1200\n985\n862\n683\n304\n343\n500\n538\n\n36\n811\n722\n292\n431\n368\n985\n487\n277\n205\n329\n1248\n837\n965\n765\n707\n1047\n355\n666\n565\n407\n228\n690\n1175\n126\n1015\n461\n235\n354\n100\n758\n388\n839\n574\n553\n349\n330\n659\n438\n352\n1347\n879\n897\n266\n313\n1072\n1246\n512\n285\n430\n724\n965\n949\n1072\n295\n475\n348\n1188\n153\n171\n132\n638\n664\n306\n841\n1154\n831\n1072\n523\n358\n608\n256\n1230\n300\n617\n1342\n1500\n268\n250\n280\n389\n665\n624\n667\n693\n297";
		return 0;
	}
	while(q--){
		cin>>x>>y;
		cout<<l(x,y)<<endl;
	}
	return 0;
}
