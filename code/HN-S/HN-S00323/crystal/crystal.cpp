#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,a[500001],ca[500000]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
		ca[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++){
		if(m-ca[i]>=0){
			cnt++;
			m-=ca[i];
		}
		else break;
	}
	printf("%d",cnt);
	return 0;
}

