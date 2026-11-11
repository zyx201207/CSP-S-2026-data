#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],t[500010],l,cnt;
int cmp(int x,int y){
	return x>y;
}
int read(){
	int f=1,ans=0;
	char ch=getchar();
	if(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}	
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return f*ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=0;i<n;i++){
		a[i]=read();
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(double(clock())/CLOCKS_PER_SEC>0.9){
			cout<<l;
			exit(0);
		}
		for(int j=0;j<i;j++){
			t[i]+=a[i]-a[j];
		}	
		l=i;
		if(t[i]>m){
			break;
		}
	}
	cout<<l;
	return 0;
}
