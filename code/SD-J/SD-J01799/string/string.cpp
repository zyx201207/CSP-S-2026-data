#include<iostream>
using namespace std;
int n;
long long a,sum;
char c;
char zfc[6000005];
int flag;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long k=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		for(long long j=0;j<a;j++){
			zfc[k++]=c;
		}
	}
	for(long long i=k-1;i>=0;i--){
		if(zfc[i]!=zfc[k-i-1]){
			zfc[i]=zfc[k-i-1];
			sum++;
			flag=1;
			for(long long j=k-1;j>=0;j--){
				if(zfc[j]!=zfc[k-j-1]){
					flag=0;
					break;
				}	
			}
			if(flag==1){
				cout<<sum;
				return 0;
			}
		}
	}
	cout<<0;
	return 0;
}
