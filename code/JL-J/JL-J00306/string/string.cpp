#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[100000005];
char c[1000005];
int main(){
	preopen("string.in","r",stdin);
	preopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long i=1,j=n,num1=a[i],num2=a[j];
	long long sum=0;int z=0,y=0;
	while(1){
	if(i==j){
		break;
	}
	
	if(z==1){
		num1+=a[i];
	}
	if(y==1){
		num2+=a[j];
	}
	z=0,y=0;
	if(num1>num2){
		num1-=num2;
		if(c[i]!=c[j]){
			sum+=num2;
		}
		num2=0;
		j--;
		y=1;
	}else if(num2>num1){
		num2-=num1;
		if(c[i]!=c[j]){
			sum+=num1;
		}
		num1=0;
		i++;
		z=1;
	}else if(num1==num2){
		if(c[i]!=c[j]){
			sum+=num1;
		}
		num1=0;
		num2=0;
		if(j-1==i){
			break;
		}
		i++;j--;
		z=1;
		y=1;
	}
}
	cout<<sum;
	
	return 0;
}
