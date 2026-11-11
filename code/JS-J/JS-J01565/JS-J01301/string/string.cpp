#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long s=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
	return s;
}
long long n,ans,I,J,K;
vector<long long>a;
vector<long long>c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=0;i<n;i++){
		int a1=read();
		char c1;
		cin>>c1;
		a.push_back(a1);
		c.push_back(c1);
	}
	for(int i=0,j=n-1;i<n||j>=0;){
		if(c[i]!=c[j])ans+=min(I+a[i],J+a[j])-max(I,J);
		if(i+1<n&&I+a[i]<=J+a[j]-1){I+=a[i];i++;}
		else if(j>0&&J+a[j]<=I+a[i]-1){J+=a[j];j--;}
		else if(i+1<n&&j>0){I+=a[i];i++;J+=a[j];j--;}
		else break;
	}
	cout<<ans/2;
	return 0;
}
