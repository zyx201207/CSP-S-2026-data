#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,w[500005],dp[500005],dis[500005],xx,ss[100005],ee[100005],ans[100005]={0};
int f;
struct xiann{
	vector<int> zhan;
	vector<int> t;
}xian[505];

struct dian{
	vector<int> mudi;
	vector<int> t;
}a[500005];

void diss(int s,int e){
	dis[s]=0;
	while(1){
		f=0;
		//寻找dis最小值 
		for(int i = 1;i<=m;i++){
			if(dp[i]==0){
//				cout << i << endl;
				if(f==0){
					f=i;
				}else if(dis[f]>dis[i]){
//					cout << dis[f]<<' '<<dis[i]<<endl;
					f=i;
				}
//				cout << f << endl;
			}
		}
//		cout<<f<<endl; 
		if(f==0){
			return;
		}
		dp[f]=1;
		for(int i = 1;i<a[f].mudi.size();i++){
			dis[a[f].mudi[i]]=min(dis[a[f].mudi[i]],dis[f]+a[f].t[i]);
//			cout << "dian:"<<a[f].mudi[i]<<"zuixiao:"<<dis[a[f].mudi[i]]<<endl;
		}
	}
}

int main(){
	freopen("subway.in ","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++){
		cin >> w[i];
		a[i].mudi.push_back(0);
		a[i].t.push_back(1000000000);
	}
	for(int i = 1;i<=n;i++){
		cin >> k;
		//占用0位 
		xian[i].zhan.push_back(0);
		xian[i].t.push_back(1000000000);
		for(int j = 1;j<=k;j++){
			cin >> xx;
			xian[i].zhan.push_back(xx);
			cin >> xx;
			xian[i].t.push_back(xx);
		}
		//建图
		for(int j = 1;j<=k;j++){
//			cout << "点："<<xian[i].zhan[j]<<endl;
			for(int l = 1;l<=k;l++){
				if(l==j){
					continue;
				}
				a[xian[i].zhan[j]].mudi.push_back(xian[i].zhan[l]);
				a[xian[i].zhan[j]].t.push_back(xian[i].t[j]+xian[i].t[l]);
//				cout << "通向"<<a[xian[i].zhan[j]].mudi[a[xian[i].zhan[j]].mudi.size()-1]<< "点，耗费"<<a[xian[i].zhan[j]].t[a[xian[i].zhan[j]].t.size()-1]<<"时间"<<endl; 
			}
		}
	}
//	//输出图
//	for(int j = 1;j<=m;j++){
//		cout << "点："<<j<<endl;
//		for(int l = 1;l<a[j].mudi.size();l++){
//			cout << "通向"<<a[j].mudi[l]<< "点，耗费"<<a[j].t[l]<<"时间"<<endl; 
//		}
//	}
	for(int kkk = 1;kkk<=q;kkk++){
		cin >> ss[kkk] >> ee[kkk];
	}
	for(int kkk = 1;kkk<=q;kkk++){
		if(ans[kkk]==0){
			for(int j = 1;j<=m;j++){
				dp[j]=0;
				dis[j]=1000000000;
			}
			diss(ss[kkk],ee[kkk]);
		}else{
			continue;
		}
		for(int j = 1;j<=q;j++){
			if(ss[j]==ss[kkk]){
				ans[j]=dis[ee[j]]+w[ss[j]]+w[ee[j]];
			}
		}
	}
	for(int kkk = 1;kkk<=q;kkk++){
		cout << ans[kkk]<<endl;
	}
	return 0;
}
