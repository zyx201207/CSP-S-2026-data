#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],x,f,g,v,aa;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		b[i]=a[i]-a[i-1];
	}
	sort(b,b+n-1);
	x=b[0];
	f=a[0];
	for(int i=1;i<n;i++){
		if(b[i]==0)
			continue;
		if(x+x+b[i]<=m){
			for(int j=1;j<n;j++){
				if(a[j]-a[j-1]==b[i]&&v+b[i]<=m){
					v+=b[i];
					aa=a[j-1];
					a[j-1]=a[j];
					for(int k=j-2;k>=0;k--)
						if(a[k]==aa&&v+b[i]<=m){
							a[k]=a[j];
							v+=b[i];
						}
					break;
				}
			}
			x+=b[i]+x;
			f=a[i];
		}
	}
	for(int i=0;i<n;i++)
		if(a[i]==f)
			g++;
	cout<<g;
}
