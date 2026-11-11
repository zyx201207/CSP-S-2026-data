#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],xian_tai[N][100],tot[N];
bool f[N];
struct node{
	int next,xian;
};
struct node2{
	int next,tot,xian;
	bool operator<(const node2& s)const{
		return s.tot<tot;
	}
};
vector<node>z[N];
priority_queue<node2>qu;
vector<int>belong[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k,last=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,t;
			cin>>u>>t;
			z[last].push_back({u,i});
			last=u;
			belong[u].push_back(i);
			xian_tai[u][i]=t;
		}
	}
	for(int i=1;i<=q;i++){
		int zw,ws;
		cin>>zw>>ws;
		memset(tot,0x3f,sizeof tot);
		//if(belong[u])
		tot[zw]=a[zw];
		qu.push({zw,a[zw],0});
		while(!qu.empty()){
			node2 fr=qu.top();
			qu.pop();
			//if(f[fr.next])continue;
			f[fr.next]=1;
			for(node v:z[fr.next]){
				for(int xian:belong[v.next]){
					//cout<<v.next<<' ';
					//cout<<tot[v.next]<<endl;
					if(xian!=v.xian){
						//cout<<"???"<<endl;
						//cout<<tot[fr.next]<<' '<<xian_tai[fr.next][v.xian]<<' '<<xian_tai[v.next][v.xian]<<endl;
						if(tot[fr.next]+xian_tai[fr.next][v.xian]+xian_tai[v.next][v.xian]+xian_tai[v.next][xian]<tot[v.next]){
							tot[v.next]=tot[fr.next]+xian_tai[fr.next][v.xian]+xian_tai[v.next][v.xian]+xian_tai[v.next][xian];
							
						//	cout<<v.next<<endl;cout<<"???";
						}
						qu.push({v.next,tot[fr.next]+xian_tai[fr.next][v.xian]+xian_tai[v.next][v.xian]+xian_tai[v.next][xian],xian});
					}	
					
					if(xian==v.xian){
						//cout<<fr.next<<' '<<v.xian<<endl;
						//cout<<"!!!"<<endl;
						tot[v.next]=min(fr.tot,tot[v.next]);
						//cout<<tot[v.next]<<endl;
						qu.push({v.next,tot[v.next],v.xian});
						//cout<<v.next<<endl;
					}
					//cout<<xian<<' '<<v.xian<<endl;
					
				}
			}
		}
		cout<<tot[ws]+a[ws]<<endl;
	}
	return 0;
} 
//freopen别注释；测试输出要删去；
//文件夹、文件名写对了吗；
//freopen输入输出文件名写对了吗 
//函数return了吗  
