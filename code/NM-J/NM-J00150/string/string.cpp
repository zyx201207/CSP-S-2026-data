#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum = 0;
	long long num[n];
	char c[n];
	for(int i = 0;i < n;i++){
		cin>>num[i]>>c[i];
		sum += num[i];
	}
	long long ans = 0;
	int left_least = num[0];
	int right_least = num[n-1];
	int left = 0;
	int right = n-1;
	long long bit = 1;
	for(;bit <= sum/2;){
		if(c[left] != c[right]){
			ans += min(left_least,right_least);
		}
		bit += min(left_least,right_least);
		if(left_least > right_least){
			left_least -= right_least;
			right--;
			right_least = num[right];
		}else if(left_least < right_least){
			right_least -= left_least;
			left++;
			left_least = num[left];
		}else{
			left++;
			right--;
			left_least = num[left];
			right_least = num[right];
		}
	}
	cout<<ans;
	return 0;
}
