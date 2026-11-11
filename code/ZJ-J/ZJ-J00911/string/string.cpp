#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ah[200005],su,sum;
char c[200005],ch[200005];
string s;
int main(){
	cin>>n;
	int flag=0,flag2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i!=1&&a[i]!=a[i-1]){
			flag=1;
		}
		if(i!=1&&c[i]!=c[i-1]){
			flag2=1;
		}
		su+=a[i];
	}
	if(flag2==0){
		cout<<0;
		return 0;
	}
	else if(flag==0){
		for(int i=1,j=n-i+1;i<=n;i++){
			if(c[i]!=c[j]){
				sum+=a[i];
			}
		}
		cout<<sum;
		return 0;
	}
	for(int i=1,j=n-i+1;i<=n;i++){
		ah[j]=a[i],ch[j]=c[i];
	}
	for(int i=1;i<=su;i++){
		int zms=0;
		char zmz,zmh;
		for(int j=1;j<=n;j++){
			if(zms+a[j]>=i){
				zmz=c[j];
				break;
			}
			zms+=a[j];
		}
		zms=0;
		for(int j=1;j<=n;j++){
			if(zms+ah[j]>=i){
				zmh=ch[j];
				break;
			}
			zms+=ah[j];
		}
		if(zmz!=zmh){
			sum++;
		}
	}
	cout<<sum/2;
	return 0;
}
