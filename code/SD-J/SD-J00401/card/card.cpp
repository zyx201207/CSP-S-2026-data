#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int k=1;k<=n;k++){
		//cout<<k<<":"<<endl; 
		int f[200005]={},b[100005]={},len=0;
		for(int i=k;i<=n;i++){
			if(f[a[i]]!=0){ 
				int x=len;
				len=len-(len-f[a[i]]+1);
				for(int j=f[a[i]];j<=x;j++){
					f[b[j]]=0;
					b[j]=0;
				}
			}
			len++;
			f[a[i]]=len;
			b[len]=a[i];
			
//			for(int j=1;j<=m;j++){
//				cout<<f[j]<<" ";
//			}
//			cout<<endl;
//			
//			for(int j=1;j<=len;j++){
//				cout<<b[j]<<" ";
//				}
//			cout<<endl<<len<<endl<<endl;
		}	
		for(int j=1;j<=m;j++){
			if(f[j]!=0) ans[j]++;
		}
//		for(int j=1;j<=n;j++){
//			cout<<ans[j]<<" ";
//		}
//		cout<<endl;
	}
	
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
