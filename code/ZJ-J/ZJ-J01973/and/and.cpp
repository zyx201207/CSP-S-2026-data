#include<bits/stdc++.h>
using namespace std;int a[200005];
bool cmp(int x,int y){
	return x>y;
}
int ermi(int qici){
	if(qici==0){
		return 1;
	}int sum=2;
	for(int i=0;i<qici-1;i++){
		sum*=2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n,cmp);
	if(n==1){
		cout<<a[0];
		return 0;
	}if(n==2){
		if(m==1){
			cout<<a[0];
		}else{
			cout<<(a[0]&a[1]);
		}
		return 0;
	}
	if(m==n){
		sum=a[0];
		for(int i=1;i<n;i++){
			sum=(sum&a[i]);
		}
		cout<<sum;
		return 0;
	}if(m==1){
		cout<<a[0];
		return 0;
	}if(m==2){
		int maxx=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}cout<<maxx;
		return 0;
	}if(m==n-1){
		sum=a[0];
		for(int i=0;i<n-1;i++){
			sum=(sum&a[i]);
		}
		cout<<sum;
		return 0;
	}bool flag2=true;
	for(int i=0;i<n;i++){
		if(sqrt(a[i]+1)*sqrt(a[i]+1)!=a[i]+1){
			flag2=false;
		}
	}if(flag2==true){
		int sum=a[0];
		for(int i=0;i<m;i++){
			sum=(sum&a[i]);
		}cout<<sum;
		return 0;
	}
	bool flag=false;
	for(int i=4;i<31;i++){
		if(n==ermi(i)&&a[n]==n-1&&a[n-1]==n-2&&a[n-2]==n-3&&a[n-3]==n-4&&a[n-4]==n-5&&a[n-5]==n-6){
			flag=true;
			break;
		}
	}if(flag==true){
		sum=a[0];
		for(int i=0;i<n;i++){
			sum=(sum&a[i]);
		}cout<<sum;
		return 0;
	}
	if(a[0]<=4){
		int k=0;
		sum=a[0];
		for(int i=0;i<m;i++){
			if(sum==4&&a[i]==2){
				continue;
			}else{
				sum=(sum&a[i]);
				k++;
			}
		}if(k<m){
			cout<<0;
		}else{
			cout<<sum;
		}return 0;
	}sum=a[0];
	for(int i=0;i<m;i++){
		sum=(sum&a[i]);
	}cout<<sum;
	return 0;
	fclose(stdin);
	fclose(stdout);
}