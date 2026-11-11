#include <bits/stdc++.h>
using namespace std;
struct node{
	int s;
	char c;
};
node arr[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		cin>>arr[i].s>>arr[i].c;
	}
	long long  l=1,r=n;
	while(l<r){
		if(arr[l].c!=arr[r].c){
			long long  x=min(arr[l].s,arr[r].s);
			cnt+=x;
			arr[l].s-=x;
			arr[r].s-=x;
			
		}else {
			long long  x=min(arr[l].s,arr[r].s);
			arr[l].s-=x;
			arr[r].s-=x;
		}
		if(arr[l].s<=0) l++;
		if(arr[r].s<=0) r--;
	}
	printf("%lld",cnt);
	return 0;
} 
