#include<bits/stdc++.h>
using namespace std;

int n,m,num,ans[500005];
int a[500005],b[500005],c[500005],f[500005],t[300005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		c[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		int n1=0;
		for(int j=i;j<=n;j++){
			ans[n1]=a[n1+1];
			if(b[a[n1+1]]==c[a[n1+1]]){
				b[a[n1+1]]--;
				f[n1]=i;
			}
			else{
				for(int g=f[n1];g<n1;g++){
					ans[g]=-1;
					c[a[n1+1]]=b[a[n1+1]];
				}
			}
		}
		int cnt=0;
		for(int j=n1;j<=n;j++){
			if(ans[j]!=-1||ans[j]!=0){
				cnt++;
			}
		}
		t[cnt]++;
		n1++;
	}
	for(int i=1;i<n;i++){
		cout<<t[i]<<" ";
	}
	
	
	return 0;
}
