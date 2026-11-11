#include<iostream>
#include<cstring>
using namespace std;
long long n;
struct node{
	string s;
	long long num;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long n1=n,cnt=0;
	for(int i=1;i<=n;i++)cin>>a[i].num>>a[i].s;
	for(int i=1;i<=n;i++){
		while(1){
			if(a[i].s!=a[n1].s)cnt+=min(a[i].num,a[n1].num);
			a[i].num-=min(a[i].num,a[n1].num),a[n1].num-=min(a[i].num,a[n1].num);
			if(!a[i].num)break;
			if(!a[n1].num)n1--;		
		}
		if(i>n1)break;
	}
	cout<<cnt;
	return 0;
} 
