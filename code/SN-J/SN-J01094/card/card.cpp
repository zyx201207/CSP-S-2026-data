#include<bits/stdc++.h>
#include<math.h>
using namespace std;
const int maxn=5e5+10;
const int maxm=3e5+10;
int a[maxn];
int cnt[maxm];//最后输出的 
int now[maxm];//a[i]是否存在	
vector<int> v;//现在的队列 
vector<int> v1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int len_v=1;//v的长度
	v.push_back(1); 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(now[a[i]]==0){//前面不存在 
			v.push_back(a[i]);//放入 
			for(int j=1;j<=len_v;j++){
				cnt[v[i]]++;
			} 
		}
		else{
			int bs;
			bool flag=1;
			for(int j=1;j<=len_v;j++){
				
				if(a[i]==a[j]){
					flag=0;
					bs=j;
				}
				if(flag=0){
					now[v[j]]--;
				}
				else v1.push_back(v[j]);
			}
			v.clear();
			v.push_back(1);
			for(int j=1;j<=bs;j++){
				v.push_back(v1[j]);
			}
		} 
		now[a[i]]++;
		len_v++;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
}
