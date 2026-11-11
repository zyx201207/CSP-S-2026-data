#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector <int> t(n+5,0);
		vector <int> f(n+5,0);
		for(int j=i;j<=n;j++){
			if(t[a[j]]==0){
				t[a[j]]=1;
				f[a[j]]=j;
			}
			else {
				for(int k=f[a[j]];k<=j;k++)t[a[k]]=0;
				t[a[j]]=1;
				f[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(t[j]==1){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}	                               
