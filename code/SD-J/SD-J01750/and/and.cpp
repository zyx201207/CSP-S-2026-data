#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int arr[200010];
int ss;
int aa;
int qq=INT_MIN;
void an(int s){
	ss++;
	aa=arr[ss];
	if(ss==m){
		cout << aa;
	}
	for(int i=s+1;i<=n;i++){
		aa&=arr[i];
		qq=max(qq,aa);
		an(i);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int b=0;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		if(arr[i]!=i-1){
			b=1;
		}
	}
	sort(arr+1,arr+1+n);
	if(m==1){
		cout << arr[n];
	}else if(m==n){
		int ans=arr[1];
		for(int i=2;i<=n;i++){
			ans&=arr[i];
		}
		cout << ans;
	}else if(m==2){
		int max_n=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int ans=arr[i];
				ans&=arr[j];
				max_n=max(max_n,ans);
			}
		}
		cout << max_n;
	}else if(m==n-1){
		int a=0;
		for(int i=1;i<=n;i++){
			if(arr[i]%2==1){
				a=1;
				break;
			}
		}
		if(a==0){
			cout << 0;
		}else{
			cout << 1;
		}
	}else if(arr[n]<4){
		int a1=0,a2=0,a3=0,a0=0;
		for(int i=1;i<=n;i++){
			if(arr[i]==0){
				a0++;
			}
			if(arr[i]==1){
				a1++;
			}
			if(arr[i]==2){
				a2++;
			}
			if(arr[i]==3){
				a3++;
			}
		}
		if(m<=a3){
			cout << 3;
		}else if(m<=a3+a2){
			cout << 2;
		}else if(m<=a1+a3){
			cout << 1;
		}else{
			cout << 0;
		}
	}else if(n==1){
		cout << arr[1];
	}else if(n<=20){
		an(1);
	}else if(b==0){
		int ans=arr[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans&=arr[i];
		}
		cout << ans;
	}else{
		cout << arr[n-m+1];
	}
	return 0;
}
