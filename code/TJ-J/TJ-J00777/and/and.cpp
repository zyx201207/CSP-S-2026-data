#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt=0,ans=0;
	bool flag=true;
	cin >> n >> m;
	int a[200002],b[n+11],c[111111];
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=m;i++) b[i]=a[i];
	while (flag){
		c[cnt+1]=1;
		for (int i=1;i<=m;i++){
			if (b[i]%2==0) c[cnt+1]=0;
			b[i]/=2;
			if (b[i]==0){
				flag=false;
				break;
			} 
		}
		cnt++;
	}
	for (int i=1;i<=cnt;i++){
		ans+=c[i]*pow(2,i-1);
		
	}
	cout << ans;
	return 0;
}
