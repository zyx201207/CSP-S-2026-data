#include<bits/stdc++.h>
using namespace std;
long long n,sum,a[200010],s1[200010],s2[200010],len,x1,x2,ans,s,x=1,y=1;
char c[200010],ch1[200010],ch2[200010],y1,y2;
string st1,st2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	for(int i=1;i<=n-sum;i++){
		s1[i]=a[i+sum];
		ch1[i]=c[i+sum];
		if(c[i+sum]==c[i+sum+1])s1[i]+=a[i+sum+1],sum++;
		len=n-sum;
		s2[len+1-i]=s1[i];
		ch2[len+1-i]=ch1[i];
	}
	len=0;
	x1=s1[1],y1=ch1[1],x2=s2[1],y2=ch2[1];
	for(int i=1;len+1<=(s+1)/2;i++){
		if(y1!=y2)ans+=min(x1,x2);
		if(x1>=x2){
			x++,x1-=x2,x2=s2[x],y2=ch2[x];
		}
		else if(x1<x2){
			y++,x2-=x1,x1=s1[y],y1=ch1[y];
		}
		len+=min(x1,x2);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}              