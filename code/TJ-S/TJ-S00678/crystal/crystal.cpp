#include<bits/stdc++.h>
using namespace std;
struct ele{
	long long a[10005]={0};
	long long sum;
	long long num;
};
ele crystal[10005];
bool cmp(ele a,ele b){
	return a.sum<b.sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>crystal[i].num;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			crystal[i].a[j]=abs(crystal[i].num-crystal[j].num);
		}
	}
	for(long long i=1;i<=n;i++){
		long long cnt=0;
		for(long long j=1;j<=n;j++){
			cnt+=crystal[i].a[j];
		}
		crystal[i].sum=cnt;
//		cout<<crystal[i].sum<<" ";
	}
//	cout<<endl;
	sort(crystal+1,crystal+n+1,cmp);
//	cout<<crystal[1].num<<endl;
	sort(crystal[1].a+1,crystal[1].a+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<crystal[1].a[i]<<" ";
//	}
//	cout<<endl;
	long long cnt=0;
	while(m>=0){
//		cout<<cnt<<" "<<m<<" "<<abs(crystal[1].a[cnt+1])<<" "<<crystal[1].a[cnt+1]<<endl;
		m-=abs(crystal[1].a[cnt+1]);
		cnt++;
	}
	if(m<0){
		cnt--;
	}
	cout<<cnt;
	return 0;
} 
