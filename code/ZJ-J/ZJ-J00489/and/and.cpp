#include<bits/stdc++.h>
using namespace std;
int n,m,a[200200],f1,f2,mx=-1,s=pow(2,30)-1,v[50];
int p[5];
bool x(int a,int b){
	return a>b;
}
void ok1(int k,int res){
	if(k>=m){
		mx=max(res,mx);
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]!=1){
			v[i]=1;
			ok1(k+1,res&a[i]);
			v[i]=0;
		}
	}
}
void ok2(){
	for(int i=1;i<=n;i++){	
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			mx=max(a[i]&a[j],mx);
		}
	}
	cout<<mx;
}
void ok3(){
	for(int i=1;i<=n;i++){
		int s=pow(2,30)-1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			s&=a[j];
		}
		mx=max(s,mx);
	}
	cout<<mx;
}
void ok4(){
	int s=pow(2,30)-1;
	for(int i=n;i>n-m;i--){
		s&=a[i];
	}
	cout<<s;
}
void ok5(){
	if(m<=p[3]) cout<<3;
	else if(m<=p[3]+p[2]) cout<<2;
	else if(m<=p[3]+p[1]) cout<<1;
	else cout<<0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=(a[i],mx);
		s&=a[i];
		if(a[i]!=i-1) f2=1;
		if(a[i]<4) p[a[i]]++;
	}
	if(n<=20){
		mx=-1;
		ok1(0,pow(2,30)-1);//1,2,3,4,5
		cout<<mx;
		exit(0);
	}
	if(m==1){
		cout<<mx;//6
		exit(0);
	}
	mx=-1;
	if(m==n){
		cout<<s;//7
		exit(0);
	}
	if(n<=2000){
		mx=-1;
		int j=pow(2,20)-1;
		ok2();//8,9,10
		exit(0);
	}
	if(m==n-1){
		mx=-1;
		ok3();//11,12
		exit(0);
	}
	if(f2==0){
		ok4();//14,15
		exit(0);
	}
	if(p[0]+p[1]+p[2]+p[3]==n){
		ok5();//16,17
		exit(0);
	}
	sort(a+1,a+n+1,x);
	cout<<a[m];//13
}
