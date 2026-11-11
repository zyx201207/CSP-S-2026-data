#include<bits/stdc++.h>
using namespace std;
long long a[500010],s[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,q=0,p=1,i=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[3]==a[4]) p++;
	while(m>0){
		q=a[3]-a[i];
		p++;
		i++;
		m-=q;
	}
	cout<<p;
	return 0;
}

