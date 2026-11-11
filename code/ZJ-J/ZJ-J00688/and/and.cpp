//Trick||Treat!
#include <bits/stdc++.h>
using namespace std;
int im[32]={0},a[200005]={0},b[200005]={0};
bool searchim(int t){
	for(int i=1;i<=30;i++){
		if(t==im[i]){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int cnt=1;
	for(int i=1;i<=30;i++){
		cnt=cnt*2;
		im[i]=cnt-1;
	}
	//cout<<im[30]<<endl;
	int np=1,n,m,maxim=0,maxn=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(searchim(a[i]) && a[i]>maxim){
			maxim=a[i];
		}
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=maxim){
			b[np++]=a[i];//sortbuyongjia1le 
		}
	}
	sort(a+1,a+n+1);
	sort(b+1,b+np);
	//cout<<n<<" "<<np<<endl;
	int ans1=2147483647,ans2=2147483647;
	for(int i=n;i>=(n-m+1);i--){
		ans1=ans1&a[i];
		//cout<<ans1<<" ";
	}
	//cout<<endl;
	for(int i=np-1;i>=(np-m);i--){
		ans2=ans2&b[i];
		//cout<<ans2<<" ";
	}
	//cout<<endl;
	cout<<max(ans1,ans2)<<endl;
	return 0;
}
