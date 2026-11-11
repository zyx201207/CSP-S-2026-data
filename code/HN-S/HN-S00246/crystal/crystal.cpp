#include<bits/stdc++.h>
using namespace std;
int n;
long long m,x,maxx,l,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		x=m;
		l=0;
		for(int j=i;j>=0;j--)
			if(x>=a[i]-a[j]){
				x-=(a[i]-a[j]);
				l++;
			}
			else break;
		maxx=max(maxx,l);
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

