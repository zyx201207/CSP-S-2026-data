#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,mx=0,s,x=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	s=a[0];
	for(int i=1;i<n;i++){
		if(x==m) break;
		else{
			if(s>a[i]){
				s=max(s,s&a[i]);
				x++;
			}
			if(s>mx){
				mx=s;
			}
			else{
				s=a[i];
				x=1;
			}
		}
		
	}
	cout<<mx;
	return 0;
}