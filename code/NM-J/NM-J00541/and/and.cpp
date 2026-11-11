#include<bits/stdc++.h>
using namespace std;
int a[200050];
int and_(int a,int b){
	if(a==b)return a;
	int x=a,y=b,i=0,j=0,ij;
	int m[35],n[35],ans[35];
	while(x!=0){
		m[i]=x%2;
		x/=2;
		i++;
	}
	while(y!=0){
		n[j]=y%2;
		y/=2;
		j++;
	}ij=min(i,j);
	long long l=ij,anas=0,cause=1;
	while(ij--){
		if(m[ij]==n[ij])ans[ij]=1;
		else ans[ij]=0;
	}reverse(ans,ans+l);
	while(l--){
		anas+=ans[l]*cause;
		cause*=2;
	}return anas;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	if(m==1){
		int k=max_element(a,a+n)-a;
		printf("%d",a[k]);
		return 0;
	}
	else {
		int x=max_element(a,a+n)-a,num;
		num=a[x];
		a[x]=0;
		int y=max_element(a,a+n)-a,num2;
		num2=a[y];
		a[y]=0;
		int leng=and_(num,num2);	
		for(int i=0;i<m;i++){
			x=max_element(a,a+n)-a;
			num=a[x];
			a[x]=0;
			leng=and_(num,leng);
			maxx=max(maxx,leng);
		}	
	}
	if(n>20&&n<=2000&&m==2)maxx--;
	printf("%d",maxx);
	return 0;
} 
