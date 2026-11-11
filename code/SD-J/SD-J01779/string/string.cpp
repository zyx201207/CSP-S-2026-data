#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e7+10;
int n,ans;
int num[N];
char str[N];
int deta_tot[M],before[M/2];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int sum_num=0;//所有num之和 
	for(int i=1;i<=n;i++){
		cin>>num[i]>>str[i];
		sum_num+=num[i];
	}
	int flag_tp=1;//特判标记变量 
	for(int i=2;i<=n;i++){
		if(str[i-1]!=str[i]){
			flag_tp=0;
			break;
		}
	}
	if(flag_tp==1){
		cout<<0;
		return 0;
	}
	int cnt=1;//当前 deta_tot长度 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=num[i];j++){
			deta_tot[cnt]=str[j];
			cnt++;
		}
	}
	int mid,mid2;//合成所有str的中间项 
	if(sum_num%2==1){
		mid=ceil(sum_num/2);
		for(int i=mid-1;i>=1;i--){
			before[mid-i]=deta_tot[i];
		}
		for(int i=1;i<=mid-1;i++){
			if(before[i]!=deta_tot[i+mid]){
				ans++;
			}
		}
		cout<<ans+1;
	}
	else{
		mid=sum_num/2;
		mid2=mid+1;
		for(int i=mid-1;i>=1;i--){
			before[mid-i]=deta_tot[i];
		}
		if(deta_tot[mid]!=deta_tot[mid2]){
			ans++;
		}
		for(int i=1;i<=mid-1;i++){
			if(before[i]!=deta_tot[i+mid+1]){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
