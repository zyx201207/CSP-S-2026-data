#include<bits/stdc++.h>
using namespace std;
long long l,r,n,sum,mid,cntl,cntr,a[500010];
char c[500010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		a[i]+=a[i-1];
		//cout<<a[i-1]+1<<' '<<a[i]<<'\n';
	}
	l=1,r=a[n],mid=l+(r-l)/2;
	cntl=1,cntr=n-1;
	while(l<mid&&r>mid){
		if(a[cntl]-l+1<r-a[cntr]){
			if(c[cntl]!=c[cntr+1])sum+=a[cntl]-l+1;
			long long jian=a[cntl]-l+1;
			l+=jian;
			r-=jian;
			cntl++;
		}else if(a[cntl]-l+1>r-a[cntr]){
			if(c[cntl]!=c[cntr+1])sum+=r-a[cntr];
			long long jian=r-a[cntr];
			l+=jian;
			r-=jian;
			cntr--;
		}else{
			if(c[cntl]!=c[cntr+1])sum+=a[cntl]-l+1;
			long long jian=a[cntl]-l+1;
			l+=jian;
			r-=jian;
			cntl++,cntr--;
		}
	}
	cout<<sum;
	return 0;
}
//woyitouxiangwoyiqiufowoyiwuli
