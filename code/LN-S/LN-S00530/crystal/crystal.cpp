#include<bits/stdc++.h>
using namespace std;
long long why,xdy;
long long a[500001],b[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>why>>xdy;
	for(long long i=1;i<=why;i++){
		cin>>a[i];
	}
	sort(a+1,a+why+1);
	if(a[1]<0) {
	for(int i=1;i<=why;i++) {
		a[i]+=abs(a[1])+1;
	}
}
	b[0]=0;
	for(long long i=1;i<=why;i++){
		b[i]=a[i]+b[i-1];
	}
	long long l=0,r=why;
	while(l<r){
	  if((r-l)*a[r]-b[r]+b[l]>=xdy){
		  long long l1=l++;
		  long long r1=r--;
		  if((r1-l+1)*a[r1]-b[r1]+b[l]<(r-l1+1)*a[r]-b[r]+b[l1]) r--;
		  else l++;
		  continue;
	  }
	  break;
	}
	cout<<r-l+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

