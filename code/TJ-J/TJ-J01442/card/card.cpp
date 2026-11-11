#include<bits/stdc++.h>
using namespace std;
int a[100005],p[100005],ans[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}int j=n;
	for(int i=n-1;i>=0;i--){
		if(p[a[i]]!=0){
			for(int k=i+1;k<p[a[i]];k++){
				ans[a[k]]-=(i+1);
				//cout<<a[k]<<' '<<ans[a[k]]<<' '<<k<<endl;
			}	
			continue;
		}
		ans[a[i]]=j;
		//cout<<a[i]<<' '<<ans[a[i]]<<' '<<i<<endl;
		j--;
		p[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
