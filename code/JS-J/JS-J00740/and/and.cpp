#include<bits/stdc++.h>
using namespace std;
int a[200005];
int t[25][25];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=-1,aa,ans=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
		if(i==1)aa=a[i];
		else aa=a[i]&aa;
	}
	//for(int i=1;i<=n;i++)cout<<a[i];
	//cout<<endl;
	if(m==1)cout<<maxn;
	else if(m==n)cout<<aa;
	else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int b=a[i]&a[j];
				ans=max(ans,b);
			}
		}
		cout<<ans;
	}else if(n<=20){
		for(int i=1;i<=m;i++){
			for(int j=i;j<=n;j++){
				if(i==1)t[i][j]=a[j];
				else{
					int cnt=-1;
					for(int k=i-1;k<j;k++){
						cnt=max(t[i-1][k]&t[1][j],cnt);
					}
					t[i][j]=max(t[i][j-1],cnt);
				}
			}
		}
		
		cout<<t[m][n];
	}
	return 0;
}
