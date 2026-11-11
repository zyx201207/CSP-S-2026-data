#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
int n,m,a[N],maxm=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("one.in","r",stdin);
	freopen("one.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==m){
		int sum=a[1];
		for(int i=1;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			int sum=a[i];
			for(int j=i+1;j<=n;j++){
				sum=sum&a[j];
				maxm=max(sum,maxm);
			}
		}
		cout<<maxm;
		return 0;
	}else{
		sort(a+1,a+n+1,cmp);
		int sum=a[1];
		for(int i=2;i<=m;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
