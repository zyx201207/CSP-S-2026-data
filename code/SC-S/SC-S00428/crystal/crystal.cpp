#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,len=0,l,r,mx=1,s,mxi=0,x=1;
void f(){
	if (s-a[l-1]<=len*(a[r+1]-s) && m>=s-a[l-1] && l>1){
		m-=s-a[l-1];
		a[l-1]=s;
		l--;
		len++;
	}else if(m>=len*(a[r+1]-s) && r<n){
		m-=len*(a[r+1]-s);
		for (int i=l;i<=r;i++){
			a[i]=a[r+1];
		}
		s=a[r+1];
		r++;
		len++;
	}else{
		m=-1;
	}
	return;
}
int main(){
	freopen("crystal.in","r",stdin);//文件读写，记得把txt删了 
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	for (int i=2;i<=n;i++){
		if (x>=mx){
			mxi+=mx;
			mx=x;
		}
		if (a[i]==a[i-1]){
			if (a[i-1]==a[mxi]) mx++;
			else x++;
		}else{
			x=1;
		}
	}
	cout<<mxi<<endl<<mx<<endl;
	l=mxi,r=mxi+mx-1,len=mx,s=a[mxi];
	while (m>0){
		f();
	} 
	cout<<len;
	return 0;
}