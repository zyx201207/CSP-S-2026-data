#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+10];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);//排序 
		}
	}
	
	int k=a[1]+m;
	int max1;//记录可达到的平均最大值下标 
	for(int i=1;i<=n;i++){
		if(k<a[i]){
			max1=i-1;
			break;
		}
	}

	int sum=0;//暂时总和 
	for(int i=1;i<=max1;i++){
		sum+=a[i];
		if(sum+m>=max1*a[max1]){
			cout<<max1;
			return 0;
		}
	}
	max1--;
	for(int i=1;i<=max1;i++){
		sum+=a[i];
		if(sum+m>=max1*a[max1]){
			cout<<max1;
			return 0;
		}
	}
	max1--;
	for(int i=1;i<=max1;i++){
		sum+=a[i];
		if(sum+m>=max1*a[max1]){
			cout<<max1;
			return 0;
		}
	}
	max1--;
	for(int i=1;i<=max1;i++){
		sum+=a[i];
		if(sum+m>=max1*a[max1]){
			cout<<max1;
			return 0;
		}
	}
	max1--;
	for(int i=1;i<=max1;i++){
		sum+=a[i];
		if(sum+m>=max1*a[max1]){
			cout<<max1;
			return 0;
		}
	}
	max1--;
	for(int i=1;i<=max1;i++){
		sum+=a[i];
		if(sum+m>=max1*a[max1]){
			cout<<max1;
			return 0;
		}
	}
	max1--;
	for(int i=1;i<=max1;i++){
		sum+=a[i];
		if(sum+m>=max1*a[max1]){
			cout<<max1;
			return 0;
		}
	}
	max1--;
	for(int i=1;i<=max1;i++){
		sum+=a[i];
		if(sum+m>=max1*a[max1]){
			cout<<max1;
			return 0;
		}
	}
	return 0;
}
	
