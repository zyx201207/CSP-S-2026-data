//yangzirui xianjiaotongdaxuefushuzhongxue SN-J00703
#include<bits/stdc++.h>
using namespace std;
struct s{
	long long num;
	char c;
}a[200005];
int n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	for(int i=1,k=n;i<k;){
		if(a[i].num>a[k].num){
			if(a[i].c!=a[k].c) ans+=a[k].num;
			a[i].num-=a[k].num;
			k--;
		}else if(a[i].num<a[k].num){
			if(a[i].c!=a[k].c) ans+=a[i].num;
			a[k].num-=a[i].num;
			i++;
		}else{
			if(a[i].c!=a[k].c) ans+=a[i].num;
			i++;k--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
