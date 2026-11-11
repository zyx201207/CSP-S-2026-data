#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],cnt[400010];
vector<int> v;
int f(vector<int> v,int a){
	int k=v.size();
	for(int i=0;i<k;i++){
		if(v[i]==a){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int u=1;u<=n;u++){
		for(int i=u;i<=n;i++){
			int x=f(v,a[i]);
			if(x==-1) v.push_back(a[i]);
			else{
				int len=v.size();
				for(int i=x;i<len;i++) v[i]=0;
				v.push_back(a[i]);
			}
		}
		int len=v.size();
		for(int i=0;i<len;i++) cnt[v[i]]++;
		v.clear();
	}
	for(int i=1;i<m;i++) printf("%d ",cnt[i]);
	printf("%d",cnt[m]);
	return 0;
}
