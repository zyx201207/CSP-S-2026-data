#include<bits/stdc++.h>
using namespace std;
const int N=5e5+55; 
int n;long long m;
long long a[N];
long long rd(){
	char ch;long long ff=0;int fu=1;
	ch=getchar();
	while(ch!=' '&&ch!='\n'){
		if(ch=='-')fu=-1;
		else ff=ff*10+(int)(ch-'0');
		ch=getchar();
	}
	return ff*fu;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	n=rd();
	m=rd();
	for(int i=1;i<=n;i++)a[i]=rd();
	sort(a+1,a+n+1);
	long long mm=m;int ans=-1;
	int l=0;
	for(int i=n;i>=2;i--){
		while(mm>=0){
			if(i-l<0||i>n)break;
			if(mm-(a[i]-a[i-l])>=0){mm=mm-(a[i]-a[i-l]);l++;ans=max(l,ans);}
			else break;
		}
		if(i-l<0||i>n)break;
		mm=mm+(a[i]-a[i-1])*(l-1);l--;
	}
	cout<<ans;
}
