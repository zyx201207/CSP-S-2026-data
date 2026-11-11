#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long n,ans;
long long m;
long long arr[500005];
long long arrsum[500005];
long long pow2[25];

long long interval_req(long long curr, long long others){
	if(curr<=others)return interval_req(curr,curr-1);
	long long x=arr[curr]*others;
	x-=(arrsum[curr-1]-arrsum[curr-others-1]);
	return x;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long gunmu=1;
	for(int i=0;i<=22;i++){
		pow2[i]=gunmu;
		gunmu*=2;
	}
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> arr[i];
	}
	sort(arr+1,arr+n+1);
	for(long long i=1;i<=n;i++){
		arrsum[i]=arrsum[i-1]+arr[i];
	}
	//for(int i=1;i<=n;i++){
	//	cout << arr[i] << ' ' << arrsum[i] << endl;
	//}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << interval_req(i,j) << ' ';
		}
		cout << endl;
	}*/
	for(long long i=1;i<=n;i++){
		long long pow=20;
		long long temp=0;
		while(pow>=0){
			if(temp+pow2[pow]>=i||interval_req(i,temp+pow2[pow])>m){
				pow--;
			}else{
				temp+=pow2[pow];
				pow--;
			}
		}
		//cout << temp << endl;
		if(temp+1>ans)ans=temp+1;
	}
	cout << ans;
	return 0;
} 
