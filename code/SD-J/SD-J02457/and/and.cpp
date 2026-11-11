#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[200005];
	int m,n;
	cin>>n>>m;
	if(m==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=31;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]&(1<<j)==1){
				cnt++;
			}
		}
		if(cnt>=m){	
			for(int i=1;i<=n;i++){
				if(a[i]&(1<<j)==0){
					a[i]=0;
				}
			}
		}
	}
	int c=0;
	bool flag=1;
	long long sum=2147483647;
	for(int i=1;i<=n;i++){
		if(c==m){
			break;
		}
		if(a[i]!=0){
			sum=sum&a[i];
			c++;
			flag=0;
		}
	}
	if(!(flag)){
		cout<<sum;
	}
	else{
		cout<<0;
	}
}
