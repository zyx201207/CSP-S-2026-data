#include<bits/stdc++.h>
using namespace std;
long long nn[10005],c,d,num2=0,h[10005][10005],gs=0,s=0;
int y(int a,int b){
	long long i=0,n[10005];
	for(int q=0;q<10005;q++){
		n[q]=0;
	}
	while(a!=0){
		n[i]=a%2;
		a/=2;
		i++;
	}
	long long j=0,m[10005];
	for(int q=0;q<10005;q++){
		m[q]=0;
	}
	while(b!=0){
		m[j]=b%2;
		b/=2;
		j++;
	}
	if(j>i){
		i=j;
	}
	long long x[10005];
	for(int q=0;q<10005;q++){
		x[q]=0;
	}
	for(int p=0;p<i;p++){
		if(n[p]==1 && m[p]==1){
			x[p]=1;
		}
		else{
			x[p]=0;
		}
	}
	long long num=0;
	i--;
	for(;i>=0;i--){
		num=num*2+x[i];
	}
	return num;
}
void f(int x,int sl){
	if(sl==d){
		gs++;
		return ;
	}
	for(int i=x+1;i<c;i++){
		if(sl==1){
			h[gs][0]=nn[s];
		}
		h[gs][sl]=nn[i];
		f(i,sl+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>c>>d;
	for(int i=0;i<c;i++){
		scanf("%lld",&nn[i]);
	}
	for(int i=0;i<c;i++){
		s=i;
		f(i,1);
	}
	for(int ii=0;ii<gs;ii++){	
		long long xx=h[ii][0];
		for(int jj=1;jj<d;jj++){
			xx=y(xx,h[ii][jj]);
		}
		if(xx>num2){
			num2=xx;
		}
	}
	cout<<num2;
	return 0;
}
