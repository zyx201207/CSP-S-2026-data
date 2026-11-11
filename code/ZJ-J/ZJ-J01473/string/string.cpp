#include<bits/stdc++.h>
using namespace std;
struct add{
	int num;
	char s;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long num=0;
	int f=-1;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].num>>a[i].s;
		num+=a[i].num;
	}
	long long mid=num/2;
	if(num%2==1){
		f=1;
	}
	if(num%2==0){
		f=0;
	}
	long long u=0;
	long long ans=0;
	int left=0;
	int right=n-1;
	while(u<=mid){
		int l=min(a[left].num,a[right].num);
		if(a[left].s!=a[right].s){
			ans+=l;
		}
		a[left].num-=l;
		a[right].num-=l;
		if(a[left].num==0){
			left++;
		}
		if(a[right].num==0){
			right--;
		}
		u+=l;
	}
	cout<<ans;
	return 0;
}