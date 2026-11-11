#include <bits/stdc++.h>
using namespace std;
int n,m;
int f(int x){
	int a=x;
	int sum[100000];
	int i=0;
	int b=0;
	while(a>0){
		sum[i]=a%2;
		a/=2;
		i++;
	}
	for (int j=i;j>=0;j--){
			b=b*10+sum[j];
	}
	return b;
}
int an(int x,int y){
	int a=x;
	int b=y;
	int c[10000];
	int i=1;
	while (max(a,b)>0){
		if (a%10==1&&b%10==1){
			c[i]=1;
		}else{
			c[i]=0;
		}
		i++;
		a/=10;
		b/=10;
	}
	a=0;
	int ans=1;
	int sum=0;
	for (int j=i;j>0;j--){
		a=a*10+c[j];
	}
	for (int j=0;j<i;j++){
		for (int k=0;k<j;k++){
			ans*=2;
		}
		sum+=a%10*ans;
		a/=10;
	}
	return sum;
}
int main (){
	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);

    cin>>n>>m;
    int a[n];
    for (int i=0;i<n;i++){
    	cin>>a[i];
	}
	int x=0;
	for (int i=0;i<n-m;i++){
		int sum=f(a[0]);
		for (int j=i;j<i+m-1;j++){
			for (int k=1;k<m;k++){
				sum=an(sum,a[k]); 
			}
		}
		if (sum>x){
			x=sum;
		}
	} 
	cout<<x;
	
	
	
	
	
	fclose(stdin);
 	fclose(stdout);
	return 0;
}

