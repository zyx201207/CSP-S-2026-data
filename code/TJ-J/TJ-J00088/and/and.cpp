#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],maxn;
long long Nand(int s,int end){
	long long ans=0,e[100010]={0},len;
	long long x=a[s],len1=0;
	while(x!=1&&x!=0){
		e[len1]=x%2;
		len1++;
		x=x/2;
	}
	e[len1]=x;
	long long y=a[s+1],e2[100010]={0},len2=0;
	while(y!=1&&y!=0){
		e2[len2]=y%2;
		len2++;
		y=y/2;
	}
	e2[len2]=y;
	len=max(len1,len2); 
	for(int i=0;i<=len;i++){
		if(e[i]==e2[i]&&e[i]==1) e[i]=1;
		else e[i]=0;
	}
	int h=1;
	for(int i=0;i<=len;i++){
		ans=ans+e[i]*h;
		h=h*2;
	}
	cout<<ans<<endl;
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		maxn=max(maxn,Nand(i,i+m-1));
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
