#include<bits/stdc++.h>
using namespace std;
struct akcsp{
	int l;
	char s; 
}a[200005];
struct akcsp2{
	int l2;
	char s2; 
}b[200005];
long long sum_l,ans=0;
int main(){
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i].l;
		cin>>a[i].s;
		int k=n-i+1;
		b[k].l2=a[i].l;
		b[k].s2=a[i].s;
	}
	int p=1,q=1;
	while(q!=n+1&&q!=n+1){
		if(a[p].l>b[q].l2){
			if(a[p].s!=b[q].s2) ans+=b[q].l2;
			a[p].l-=b[q].l2;
			q++;
			continue;
		}
		if(a[p].l<b[q].l2){
			if(a[p].s!=b[q].s2) ans+=a[p].l;
			b[q].l2-=a[p].l;
			p++;
			continue;
		}
		if(a[p].l==b[q].l2){
			if(a[p].s!=b[q].s2) ans+=a[p].l;
			a[p].l=0,b[q].l2=0;
			p++,q++;
			continue;
		}
	}
	cout<<ans/2; 
	return 0;
} 
