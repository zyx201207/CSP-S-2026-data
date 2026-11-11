#include<bits/stdc++.h>
using namespace std;
struct nod{
	long long num;
	char c;
};
long long n,sum;
nod a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	int i=1,j=n;
	while(j!=i){
		int s=min(a[i].num,a[j].num);
		a[i].num-=s;
		a[j].num-=s;
		if(a[i].c!=a[j].c)sum=sum+s;
		if(a[i].num==0)i++;
		if(a[j].num==0)j--;
	}
	printf("%lld",sum);
	return 0;
}
