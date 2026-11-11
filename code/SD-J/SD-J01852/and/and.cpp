#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[200005],ans=-1e9;
void YHSQISGAY(long long shu,long long jile,long long man){
	if(shu>n&&man!=m)return;
	if(man==m){
		ans=max(ans,jile);
		return;
	}		
	if(jile==0){
		YHSQISGAY(shu+1,a[shu],man+1);
		YHSQISGAY(shu+1,jile,man);
	}else{
		YHSQISGAY(shu+1,jile&a[shu],man+1);
		YHSQISGAY(shu+1,jile,man);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	YHSQISGAY(1,0,0);
	cout<<ans;
	return 0;
} 
