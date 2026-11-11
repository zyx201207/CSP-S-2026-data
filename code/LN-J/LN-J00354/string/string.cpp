#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 2e5+10;
LL hx[N],n,c,k,r,ans=0,s,v;
char a[N],b[N];
LL c1,s1;
/*void fac(LL i,LL j){
	//cout<<"zuo"<<hx[i]<<" "<<a[i]<<" "<<"you"<<hx[s-j+1]<<" "<<a[s-j+1]<<endl;
	if(c1==c){
		return ;
	}
	v++;
	if(hx[i]>hx[s-j-1]){
		//if(c1+hx[i]>c) return ;
		cout<<"zuoda"<<endl;
		//xiao diao
		c1+=hx[s-j-1];
		if(a[i]==a[s-j-1]){
			ans++;
			hx[i]-=hx[s-j-1];
			hx[s-j-1]=0;
		}
		//bu tong ,guo xia yi ge
		else{
			hx[i]-=hx[s-j-1];
			hx[s-j-1]=0;
			fac(i,j+1);
		}
	}
	else if(hx[i]==hx[s-j-1]){
		cout<<"yiyanda"<<endl;
		//xiao diao
		c1+=hx[i];
		if(a[i]==a[s-j-1]){
			ans++;
			hx[i]-=hx[s-j-1];
			hx[s-j-1]=0;
		}
			//bu tong ,guo xia yi ge
		else{
			hx[i]-=hx[s-j-1];
			hx[s-j-1]=0;
			fac(i+1,j+1);
		}
	}
	else{
		//if(c1+hx[s-j-1]>c) return ;
		cout<<"youda"<<endl;
		//xiao diao
		c1+=hx[i];
		if(a[i]==a[s-j-1]){
			ans++;
			hx[s-j-1]-=hx[i];
			hx[i]=0;
		}
		//bu tong ,guo xia yi ge
		else{
			hx[s-j-1]-=hx[i];
			hx[i]=0;
			fac(i+1,j);
		}
	}
}*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>hx[i]>>a[i];
		c+=hx[i];
	}
	//cout<<c<<" "; 
	s=c;
	s1=c;
	ans=c;
	if(c%2==1){
		c-=1;
		c/=2;
	}
	else{
		c/=2;
	}
	LL p=1;
	for(int i = 1;i<=n;i++){
		for(int j =p;j<p+hx[i];j++) b[j]=a[i];
		p+=hx[i];
	}
	for(int i = 1;i<=c;i++){
		if(b[i]!=b[s-i+1]) v++;
	}
	cout<<v;
	return 0;
}
