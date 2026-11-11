#include<iostream>
#include<algorithm>
//×¢Òâfreopen; 
using namespace std;
const int MAXN=100000001;
long long n,m;
long long sum;
long long arr[MAXN];
long long ans=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	long long sum1=sum+m;
	sum+=m;
	sum1/=n;
	sort(arr+1,arr+1+n,cmp);
	//cout<<sum;
	for(int i=n;i>=1;i--){
		if(arr[i]>sum1){
			sum-=arr[i];
		}
	}
	for(int j=1;j<=n;j++){
		if(arr[j]<=sum1){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
