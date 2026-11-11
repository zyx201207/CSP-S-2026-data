#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],f[300005],ans[300005];
int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	//我献祭林老师一亿根头发换AC
	//我献祭周扬合一万根头发换AC
	//我献祭GH一米身高换AC
	//CSP为什么不帮考生处理好数据?
	//因为他很CS 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int z=1;z<=n;z++){
		stack<int> s;
		for(int i=z;i<=n;i++){
			if(f[a[i]]==0){
				s.push(a[i]);
				f[a[i]]=1;
			}else{
				while(s.top()!=a[i]){
					f[s.top()]=0;
					s.pop();
				}
			}
		}
		for(int i=1;i<=m;i++){
			//cout<<f[i]<<" ";
			if(f[i]==1){
				//cout<<i<<" "; 
				ans[i]++;
				f[i]=0;
			}
			
		}//cout<<endl;	
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
