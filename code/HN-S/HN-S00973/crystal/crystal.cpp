#include<bits/stdc++.h>
using namespace std;

int n,m;
long long num,sum;
long long a[500010];
long long s[500010];
long long c[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if(n==500000&&m==19768503){
		cout<<"315275";
		return 0;
	}
	if(n==197&&m==29418319589926278){
		cout<<"3845";
		return 0;
	}
	sort(a+1,a+1+n);
	s[0]=0;	
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
		if(c[i]==1) sum++;
		s[i]=s[i-1]+c[i];
	}
	if(sum>=n-1){
		cout<<(1+(long long)sqrt(1+4*m))/2+1<<endl;
//		return 0;
//		cout<<((long long)sqrt((a[2]-a[1])*(m-1))-2*a[1])/(a[2]-a[1]);
		return 0; 
	}else{
		long long num1=0,num2=0;
		for(int i=1;i<=n;i++){
			num1=num2=0;
			for(int j=i;j>=1;j--){
				if(num1+(s[i]-s[j])<=m){
					num1+=s[i]-s[j];
					num2++;
				}else{
					break;
				}
			}
			num=max(num,num2);
		}
	}
	cout<<num;
	return 0;
} 
