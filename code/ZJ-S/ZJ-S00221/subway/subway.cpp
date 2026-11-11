#include<bits/stdc++.h>
#include<vector>
int m;
int w[500001];
int n;
int c,d,q;
int xr,yr;
int mt=INT_MAX;
struct R{
	int k;
	std::vector <int> a,t; 
}su[500001]; 
//struct zhan{
//	std::vector <int> xx;
//}zd[500001];
struct zhan{
	std::vector<int> zz;
	std::vector<int> cost;
}z[500001];

int ma[500001];
void f(int xz,int time){
	if(xz==yr){
		mt=std::min(mt,time+w[yr]);
		return ;
	}
//	for(int i=1;i<=m;i++){
//		std::cout<<ma[i]<<' ';
//	}std::cout<<std::endl;
	
	ma[xz]++;
	int zsize=z[xz].zz.size();
	for(int i=0;i<zsize;i++){
		ma[z[xz].zz[i]]++;
	}
	
	for(int i=0;i<zsize;i++){
		if(ma[z[xz].zz[i]]==1){
//			std::cout<<"   "<<xz<<"->"<<z[xz].zz[i]<<std::endl;
			f(z[xz].zz[i],time+z[xz].cost[i]);
			
		}
	}
	
	for(int i=0;i<zsize;i++){
		ma[z[xz].zz[i]]--;
	}
	ma[xz]--;
	
	
	return ;
}
int main(){
	std::freopen("subway.in","r",stdin);
	std::freopen("subway.out","w",stdout);
	std::cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		std::cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		std::cin>>su[i].k;
		int aa,tt;
		for(int j=1;j<=su[i].k;j++){
			std::cin>>aa>>tt;
			su[i].a.push_back(aa);
			su[i].t.push_back(tt);
		}
		
		for(int j=0;j<su[i].k;j++){
			for(int jj=j+1;jj<su[i].k;jj++){
				//if(j==jj) continue;
				z[su[i].a[j]].zz.push_back(su[i].a[jj]);
				z[su[i].a[j]].cost.push_back(su[i].t[j]+su[i].t[jj]);
				z[su[i].a[jj]].zz.push_back(su[i].a[j]);
				z[su[i].a[jj]].cost.push_back(su[i].t[j]+su[i].t[jj]);
			}
		}
	}
	
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<z[i].zz.size();j++){
//			std::cout<<" "<<z[i].zz[j]<<" ";
//		}
//		std::cout<<std::endl;
//	}
	for(int i=1;i<=q;i++){
		mt=INT_MAX;
		std::cin>>xr>>yr;
		f(xr,w[xr]);
		std::cout<<mt<<std::endl;
	}
	return 0;
}
	                