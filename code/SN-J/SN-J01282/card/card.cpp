#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],at[300005];
bool f=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]){
			f=0;
		}
		if(f){
			t[a[i]]=i;
		}
	}
	if(f==1){
		for(int i=1;i<=m;i++){
			cout<<t[i]<<" ";
		}
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			vector<int>c;
			for(int j=i;j<=n;j++){
				c.push_back(a[j]);
			}
			for(int j=i;j<=n;j++){
				int lenc=c.size();
				bool af=0;
				for(int k=0;k<lenc;k++){
					
					if(c[k]==a[j]){
						af=1;
					}
					if(af){
						c[k]=0;
					}
				}
				c.push_back(a[j]);
			}
			int lenc=c.size();
			for(int j=0;j<lenc;j++){
				at[c[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<at[i]<<" ";
	}
	return 0;
}

