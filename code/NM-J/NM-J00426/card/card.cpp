#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	
	cin>>n>>m;
	vector<int> op(m+5,0);//xiabiao
	vector<int> son(n+5,0);//xiabiao
	vector<int> a(n+5);//shuju
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(op[a[i]]==0){
			op[a[i]]=i;
		}
		else{
			int ad=op[a[i]];
			while(son[ad]!=0){
				ad=son[ad];
			}
			son[ad]=i;
		}
		
		
	}
	vector<int> ans(m+5,0);
	for(int i=1;i<=n;++i){
		int e=i+1;
		for(int j=i;j<=n;j=e){
			ans[a[j]]++;
			if(son[j]==0){
				e=j+1;
			}else{
				int ad=j,p;
				while(son[ad]!=0){
					p=ad;
					ad=son[ad];
					
				}
				e=son[p]+1;
			}
		}
		
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
		if(i!=m) cout<<" ";
	}
	return 0;
}
