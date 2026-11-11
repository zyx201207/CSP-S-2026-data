#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500005],ans,maxx;
struct A{
	int cha;
};
A sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crysral.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		for(int v=1,j=n;v<=n,j>=1;v++,j--){
			sum[v].cha=a[i]-a[j];
		} 
		int num=0;
		ans=0;
		for(int j=1;j<=n;j++){
			if(sum[j].cha<0){
				continue;//如果是－数，略过。 
			}else{
				num+=sum[j].cha;//不是就ans++，让num值加上当前的差 
				ans++;
			}
			if(num==m){//对比差集和m； 
				maxx=max(maxx,ans);
				
			}else if(num>=m){//比大小 
				maxx=max(maxx,--ans);
			}
		}
	}
	cout<<maxx;
	return 0;
}
