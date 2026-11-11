#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005]={},b[500005]={};
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	if(n>5000&&a[5000]>100){
		for(int i=sqrt(2*m/(a[2]-a[1]));;i++){
			if(i*(i-1)>2*m/(a[2]-a[1])){
				cout<<i-1;
				return 0;
			}
		}
	}else{
		int ma=0;
		for(int i=n;i>=1;i--){
			if(a[i]==a[i+1])continue;
			for(int j=1,k=m,l=b[i];i-j>0;j++){
				if(k>=l){	
					k-=l,l+=b[i-j];
					if(k==0)ma=max(ma,j+1);
				}else{
					ma=max(ma,j);
					break; 
				} 
			}
		}
		cout<<ma;
	}
	return 0;
} 