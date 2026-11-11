#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],ans[N];//牌 答案 
bool b[N];
int n,m;
vector<int>v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	memset(b,false,sizeof(b));
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++){//n局相互独立的游戏
	cout << endl;
		for(int j=i;j<=n;j++){//依次打出第i张到第n张
			int u=a[j];//打出的牌 
			//cout << "u=" << u << endl;
			if(!b[u]){
				//cout << "打u=" << u << endl;//
				v.push_back(u);
				b[u]=true;
			}else{
				for(int k=v.size()-1;k>=0;k--){
					//cout << "舍u=" << v[k] << endl;//
					v.pop_back();
					b[v[k]]=false;
					if(v[k]==u)break;
				}
				v.push_back(u);
				b[u]=true;
			}
		}
		for(int j=1;j<=n;j++){
			if(b[j])ans[j]++;
			b[j]=false;
		}
		while(!v.empty())v.pop_back();
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
