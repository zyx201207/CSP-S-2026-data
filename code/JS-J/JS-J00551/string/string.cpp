#include <bits/stdc++.h>
using namespace std;
struct xxx{
	long long num;
	char type;
};
xxx a[200010];
int n;
long long sum=0;
char find(int x){
	long long summ=0;
	for(int i=1;i<=n;i++){
		summ+=a[i].num;
		if(summ>=x) return a[i].type;
	}
	return '0';
}
long long summm=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	  
	cin>>n;
	int i1;
	char i2;
	for(int i=1;i<=n;i++){
		cin>>i1>>i2;
		a[i].num=i1;
		a[i].type=i2;
		sum+=i1;
	}
	if(sum%2==1){
		for(long long i=1;i<=sum/2;i++){
			if(find(sum/2-i+1)!=find(sum/2+i+1)) summm++;
		}
	}else{
		for(long long i=1;i<=sum/2;i++){
			if(find(sum/2-i+1)!=find(sum/2+i)) summm++;
		}
	}
	cout<<summm;
	return 0;
}
