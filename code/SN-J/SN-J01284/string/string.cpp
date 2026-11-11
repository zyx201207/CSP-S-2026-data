#include<bits/stdc++.h>
using namespace std;
int n;
int a[200001];
char b[200001];
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i],sum+=a[i];
	long long l=1,r=sum;
	int tl=1,tr=n;
	long long ans=0;
	while(l<r){
		if(a[tl]<a[tr]){
			if(b[tl]!=b[tr]) ans+=a[tl];
			l+=a[tl],r-=a[tl];
			a[tr]-=a[tl];
			tl++;
		}
		else{
			if(b[tl]!=b[tr]) ans+=a[tr];
			l+=a[tr],r-=a[tr];
			a[tl]-=a[tr];
			tr--;
		}
	}
	cout<<ans;
	return 0;
}
