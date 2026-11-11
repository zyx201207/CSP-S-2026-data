//SN-J00781 范任哲 延安市宝塔区高新学校（延安无锡实验学校） 
#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n);
		ans=a[n-1];
	}else if(m==2){
		int x;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(i==j){
					continue;
				}
				x=a[i]&a[j];
				if(x>ans){
					ans=x;
				}
			}
		}
	}else if(m==n){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans&=a[i];
		}
	}else if(m==n-1){
		int x=2147483647;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j){
					continue;
				}
				x&=a[j];
			}
			if(x>ans){
				ans=x;
			}
		}
	}else{
		sort(a,a+n);
		ans=a[n-m];
	}
	cout<<ans;
	return 0;
}
