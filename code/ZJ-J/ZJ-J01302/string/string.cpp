#include <bits/stdc++.h>
using namespace std;
long long l,s,a[200010],b[200010],f[400010];
char c[200010],d[200010];
int n,ct,l1,l2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[n-i+1]=a[i];
		d[n-i+1]=c[i];
	}
	for (int i=1;i<=n;i++){
		a[i]+=a[i-1];
		b[i]+=b[i-1];
	}
	l=a[n]+1>>1;
	for (int i=1;i<=n;i++){
		if (a[i]<l) f[++ct]=a[i];
		if (b[i]<l) f[++ct]=b[i];
	}
	sort(f+1,f+ct+1);
	f[++ct]=l;
	for (int i=0,j=0,k=1;k<=ct;k++){
		while (a[i]<f[k]) ++i;
		while (b[j]<f[k]) ++j;
		if (c[i]!=d[j]) s+=f[k]-f[k-1];
	}
	cout<<s<<"\n";
	return 0;
}
