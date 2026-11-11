#include<bits/stdc++.h>
using namespace std;

int n;
int a[200005];
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	long long len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long p1=1,p2=len,nc1=1,nc2=n,ans=0;
	while(p1<p2){
		if(a[nc1]<a[nc2]){
			if(c[nc1]!=c[nc2]) ans+=a[nc1];
			p1+=a[nc1];
			p2-=a[nc1];
			a[nc2]-=a[nc1];
			a[nc1]=0;
			nc1++; 
		}
		else{
			if(c[nc1]!=c[nc2]) ans+=a[nc2];
			p1+=a[nc2];
			p2-=a[nc2];
			a[nc1]-=a[nc2];
			a[nc2]=0;
			nc2--;
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
