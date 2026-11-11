#include<bits/stdc++.h>
using namespace std;
long long n,i,a[200010],sum,a1,a2,tp,cl,p1,t,w,j,c[200020];
char b[200010],d[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i]>>b[i],sum+=a[i];
	tp=sum/2;
	if(sum%2==1){
		for(i=1;i<=n;i++){
			cl+=a[i];
			if(cl>=tp+1)break;
		}
		a[i]--;
	}
	for(i=1;i<=n;i++){a1+=a[i];if(a1>=tp)break;}
	p1=i;
	if(a1>tp){
		n++;
		a1=a1-a[i];
		for(j=1;j<i;j++)c[j]=a[j];
		c[j]=tp-a1;c[j+1]=a[i]-tp+a1;
		for(j=i+1;j<=n;j++)d[j]=b[j-1];
		for(j=i+1;j<=n;j++)b[j]=d[j];
		for(j=i+2;j<=n;j++)c[j]=a[j-1];
		a1=0;
		for(i=1;i<=n;i++){a1+=c[i];if(a1==tp)break;}
		p1=i;
	}	
	else{for(i=1;i<=n;i++)c[i]=a[i];}
	t=1;w=n;sum=0;
	while(t<=p1&&w>p1){
		if(b[t]!=b[w])sum=sum+min(c[t],c[w]);
		if(c[t]<c[w])c[w]-=c[t],t++;
		else if(c[t]>c[w])c[t]-=c[w],w--;
		else t++,w--;
	}
	cout<<sum;
	return 0;
}
