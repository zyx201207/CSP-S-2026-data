/*#include<bits/stdc++.h>
using namespace std;
int n,q,s,w,zz,yz,zx,yx;
struct sc{
	int k,z;
	char c;
}a[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		q++;
		cin>>a[q].k>>a[q].c;
		w=w+a[q].k;
		a[q].z=w;
	}
	w=(w+1)/2;
	for(int i=1;i<=n;i++){
		if(a[i].z>w){
			w=i;
		}
		break;
	}
	zz=a[1].k;
	yz=a[q].k;
	zx=1;
	yx=q;
	while(zx<=w&&yx>=w){
		if(a[zx].c!=a[yx].c){
			s=s+min(zz,yz);
		}
		if(zz<yz){
			yz=yz-zz;
			zx++;
			zz=a[zx].k;
		}
		else if(zz>yz){
			zz=zz-yz;
			yx--;
			yz=a[yx].k;
		}
		else{
			zx++;
			yx--;
			zz=a[zx].k;
			yz=a[yx].k;
		}
	}
	cout<<s;

	return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
int n,k,z;
string s,c;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>k>>c;
		for(int i=1;i<=k;i++){
			s=s+c;
		}
	}
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]!=s[n-i-1]){
			z++;
		}
	}
	cout<<z/2;

	return 0;
}
