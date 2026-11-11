#include<bits/stdc++.h>
using namespace std;
string s;
long long ans,sum,n,a[200010];
char c[200010],top1,top2;
long long l1,l2,n1,n2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	l1=0,n1=1;
	l2=sum,n2=n;
	while(n1<=n2){
		if(c[n1]!=c[n2]){
			ans+=min(a[n1],a[n2]);
		}
		if(a[n1]<a[n2]){
			a[n2]-=a[n1];
			n1++;
		}else if(a[n1]>a[n2]){
			a[n1]-=a[n2];
			n2--;
		}
		else {
			n1++,n2--;
		}
	}
	cout<<ans;
	return 0;
} 
