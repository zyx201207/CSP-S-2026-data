#include<bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long ;
ui n,m;
ull a[200010]={};
bool cmp(ull x,ull y){//½µÐòÅÅÐò 
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(false);
	cin>>n>>m;
	for (ui i=1;i<=n;i++) cin>>a[i];
	if (m==1){			// O(sort)
		sort(a+1,a+n+1,cmp); cout<<a[1]<<endl; //O(sort)
	} else if (m==n){	// O(n-1)
		ull r=a[1];
		for (ui i=2;i<=n;i++) r=r&a[i];	// O(n-1)
		cout<<r<<endl;
	} else if (m==n-1){	// O(n*n-1)
		ull all[200010]={};
		ull r=a[2]; for(ui j=3;j<=n;j++) {r=r&a[j];} all[1]=r; // O(n-2)
		r=a[1];
		for (ui i=2;i<=n;i++){
			for(ui j=2;j<=n&&(i-j);j++) r=r&a[j];	// O(n*n-n+1)
			all[i]=r; 
		}
		sort(all+1,all+n+1,cmp); cout<<all[1]<<endl;
	} else if(m==2){	// O(n*n+sort)
		sort(a+1,a+n+1,cmp); // O(sort)
		ull r=0;
		for (ui i=1;i<=n;i++){
			for (ui j=1;j<=n&&(i-j);j++){
				r = max(r,a[i]&a[j]]);	// O(sort+n*n)
			}
		} cout<<r<<endl;
	} else {			// O(n+sort-1),²Ð²îÇ÷ÓÚÎÞÏÞ 
		sort(a+1,a+n+1,cmp); //µ¥µ÷µÝ¼õ,O(sort)
		ull r=a[1];
		for (ui i=2;i<=m;i++){
			r=r&a[j];	// O(n-1)
		} cout<<r<<endl;
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
