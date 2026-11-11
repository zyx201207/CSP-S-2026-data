#include <bits/stdc++.h>
using namespace std;
int n;
long long int sum=0;
bool cmp=true;
struct stu{
	int shu;
	char zi;
}a[10000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].shu;
		cin>>a[i].zi;
		sum+=a[i].shu;
	}
	for(int i=1;i<=n-1;i++){
		if(a[i].zi!=a[i+1].zi) cmp=false;
	}
	if(cmp) cout<<0;
	else cout<<sum/n;
	return 0;
}

