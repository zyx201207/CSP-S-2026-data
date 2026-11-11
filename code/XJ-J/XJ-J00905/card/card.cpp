#include<bits/stdc++.h>
using namespace std;
struct card{
	long long cnt;
	long long id;
};
long long arr[500010],arr_ans[300010];
card arr1[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>arr[i];
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(arr1[arr[j]].cnt==0){
				arr1[arr[j]].cnt++;
				arr1[arr[j]].id=j;
			}
			else{
				for(long long k=arr1[arr[j]].id;k<=j;k++) arr1[arr[k]].cnt=0;
				arr1[arr[j]].cnt++;
			}
		}
		for(long long j=1;j<=m;j++){
			if(arr1[j].cnt==1) arr_ans[j]++;
		}
		for(long long j=1;j<=m;j++) arr1[j].cnt=0;
	}
	for(long long i=1;i<=m;i++) cout<<arr_ans[i]<<" ";
	return 0;
}