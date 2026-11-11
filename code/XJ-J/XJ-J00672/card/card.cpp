//#include<bits/stdc++.h>
//using namespace std;
//int n,m,a[500005],b[300005],back[300005][2];
//int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//		b[a[i]]++;
//		if(b[a[i]]>1){
//			back[a[i]][1]=back[a[i]][0];
//			back[a[i]][0]=i;
//		}
//	}
//	for(int i=1;i<=n;i++){
//		b[a[i]]++;
//		vector<int> c;
//		int j;
//		if(back[a[i]][0]!=i){
//			j=back[a[i]][0];
//		}else {
//			if(back[a[i]][1]==0)j=1;
//			else j=back[a[i]][1];
//		}
//		while(j<=n){
//			
//			j++;
//		}
//	}
//	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
//	return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,a[500005],sum[300005];
//vector<int> b[300005];
//int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//		b[a[i]].push_back(i);
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=n;j)
//	}
//	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[300005],b[300005];
bool vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)vis[j]=0;
		vis[a[i]]=1;
		vector<int> x;
		x.push_back(a[i]); 
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			if(vis[a[i]]){
				while(x[x.size()-1]!=a[i]){
					x.pop_back();
				}
			}else{cout<<1;
				x.push_back(a[j]);
				vis[a[j]]=1;
			}
			//for(int k=0;k<x.size();k++)cout<<x[k]<<' ';cout<<'\n';
		}//cout<<'\n';
		for(int j=0;j<x.size();j++)sum[x[j]]++;//cout<<'\n';
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<' ';
	return 0;
}//4 3 1 2 1 3
