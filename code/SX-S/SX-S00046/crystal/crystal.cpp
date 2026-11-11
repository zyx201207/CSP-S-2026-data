#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d %lld",&n,&m);
	long long m1=m;
	char a;
	int l[n];
	for(int i=0;i<n;i++){
		scanf("%d",&l[i]);
		scanf("%c",&a);
	}
	sort(l,l+n);
	int cnt=1,max=1,j=1;
	for(int i=n-1;i>=1;i--){
		while(l[i]-l[i-j]<=m1&&i-j>=0){
			m1-=l[i]-l[i-j];
			cnt++;
			j++;
		}
		if(cnt>max)max=cnt;
		cnt=1;
		m1=m;
		j=1;
	}
	printf("%d",max);
	return 0;
}