#include<bits/stdc++.h>
using namespace std;
long long m;
int n;
long long a[500005];
int ans = 0;
bool cmp(int x,int y){
	return x>y;	
}
int x=-1;
void A_cspdsz(){
	for(int i = n;i>=1;i--){
		if(i*(i-1)/2<=m){
			printf("%d",i);
			break;
		}
	}
}
void B_cspsph(){
	for(int i = n;i>=1;i--){
		if(x*i*(i-1)/2<=m){
			printf("%d",i);
			break;
		}
	}
}
void CSPLWL(){
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++){
		int k = m;
		int num = 0;
		for(int j = i-1;j>=1;j--){
			if(k>=a[i]-a[j]){
				k-=a[i]-a[j];
				num++;
			}
			else{
				break;
			}
		}
		ans = max(ans,num+1);
	}
	printf("%d",ans);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	bool flagA = 1,flagB = 1;
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i)flagA=0;
		if(x!=a[i]-a[i-1]&&x!=-1){
			flagB = 0;
		}
		x = a[i]-a[i-1];
	}
	if(flagA){
		A_cspdsz();
	}
	else if(flagB){
		B_cspsph();
	}
	else CSPLWL();
	return 0;
}
