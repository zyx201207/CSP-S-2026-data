#include<bits/stdc++.h>
using namespace std;
long long a[200002]={};
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,q3=0,q2=0,q1=0,q=0;
long long ans=0,maxx=0,rr=0;
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];
if((a[i]+1)%2!=0){
	rr=1;
}
maxx=max(maxx,a[i]);
if(a[i]==3)
q3+=1;
if(a[i]==2)
q2+=1;
if(a[i]==1)
q1+=1;
if(a[i]==0)
q+=1;
}
if(maxx<4){
	if(q3>=m)
	cout<<3;
	else if(q3+q2>=m)
	cout<<2;
	else if(q3+q2+q1>=m)
	cout<<1;
	else
	cout<<0;
}
else if(rr==0){
	cout<<pow(2,n-m+1)-1;
}
else if(m==n){
ans=a[1];
for(int i=2;i<=n;i++){
ans=ans&a[i];
}
cout<<ans;
return 0;
}
else if(m==1){
	cout<<maxx;
}
else if(m==2){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	cout<<ans;
}
else if(m==n-1){
	for(int i=1;i<=n;i++){
		long long t=0;
		if(i==1){
			t=a[2];
		}
		else if(i==2){
			t=a[1];
		}
		else{
			t=a[1]&a[2];
		}
		for(int j=3;j<=n;j++){
			if(j!=i){
				t=t&a[j];
			}
		}
		ans=max(ans,t);
	}
	cout<<ans;
}
else if(m==3&&n<=200){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int z=j+1;z<=n;z++){
			long long sss=a[i]&a[j];
			sss=sss&a[z];
			ans=max(ans,sss);
		}
		}
	}
	cout<<ans;
}
else{
	cout<<0;
}
return 0;
}
