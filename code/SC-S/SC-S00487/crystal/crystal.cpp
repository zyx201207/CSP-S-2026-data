#include<bits/stdc++.h>
using namespace std;
struct cry{
	long long e;
	unsigned long long sum;
}a[500005];
bool cmp(cry a,cry b){
	return a.e<b.e;
}
int n;
unsigned long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].e);
	}
	sort(a+1,a+n+1,cmp);
	a[1].sum=0;
	int ans=0;
	bool f=true;
	for(int i=2,j=1;i<=n;i++){
		a[i].sum=(a[i].e-a[i-1].e)*(i-1)+a[i-1].sum;
		if(a[i].sum>m&&f){
			f=false;
			do{
				++j;
			}while(a[i].sum-((a[i].e-a[j].e)*(j-1)+a[j].sum)>m);
		}else if(a[i].sum-((a[i].e-a[j].e)*(j-1)+a[j].sum)>m){
			do{
				++j;
			}while(a[i].sum-((a[i].e-a[j].e)*(j-1)+a[j].sum)>m);
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}