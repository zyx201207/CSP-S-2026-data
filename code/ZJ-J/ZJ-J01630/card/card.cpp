#include<bits/stdc++.h>
using namespace std;
int n,m,num[300010],a[500010];
bool flag[300010];
vector<int>v[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]].push_back(i);
	}
	for(int i=n;i>=1;i--){
		int x=a[i];
		if(!flag[x]){
			bool b=1;
			for(int j=i-1;j>=1;j--){
				int y=a[j];
				if(v[y].size()>1&&v[y][v[y].size()-1]>i){
					num[x]+=i-j;
					b=0;
					break;
				}
			}
			if(b){
				num[x]+=i;
				flag[x]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}