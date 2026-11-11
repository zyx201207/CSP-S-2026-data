#include<iostream>
#include<string>
using namespace std;
const int M=2*1e5+100;
int n;
long long ans=0;
long long a[M][3];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char c;
	
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>c;
		a[i][2]=c;
	}
	
	int l=1,r=n;
	while(l<r){
		if(a[l][2]==a[r][2]){
			if(a[l][1]>=a[r][1]){
				a[l][1]-=a[r][1];
				a[r][1]=0;
			}else{
				a[r][1]-=a[l][1];
				a[l][1]=0;
			}
		}else{
			if(a[l][1]>=a[r][1]){
				ans+=a[r][1];
				a[l][1]-=a[r][1];
				a[r][1]=0;
			}else{
				ans+=a[l][1];
				a[r][1]-=a[l][1];
				a[l][1]=0;
			}
		}
		if(a[l][1]==0){l++;}
		if(a[r][1]==0){r--;}
	}
	cout<<ans;
	return 0;
}
