#include <bits/stdc++.h>
using namespace std;
struct sf{
	long long num;char c;
};
sf a[200005];
long long b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}long long temp=0;long long sum=0;
	long long i=n;long long j=1;
	while(i>j){
		if(a[i].c!=a[j].c){
			sum+=min(a[i].num,a[j].num);
			if(a[i].num>a[j].num){
				a[i].num-=a[j].num;j++;temp=a[i].num;
			}
			else if(a[i].num==a[j].num){
				i--;j++;
			}
			else{
				a[j].num-=a[i].num;i--;
			}
		}
		else{
			long long ai=a[i].num,aj=a[j].num;
			a[i].num-=min(ai,aj);
			a[j].num-=min(ai,aj);
			if(!a[i].num)i--;
			if(!a[j].num)j++;
			if(i==j)break;
		}
	}
	
	cout<<sum;
	return 0;
}
