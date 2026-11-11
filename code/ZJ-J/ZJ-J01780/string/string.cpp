#include<bits/stdc++.h>
using namespace std;
long long a[200005],d,n,m,mi;
char s[200005];
long long l=1,r,a1=0,a2=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s[i];
	}
	l=1;
	r=n;
	for(int i=1;i<=n+1;i++){
		if(r<=l){
			break;
		}
		if(a[l]-a1==a[r]-a2){
			
			if(s[l]!=s[r]){
				mi+=a[l]-a1;
			}
			l++;
			r--;
			a1=0;
			a2=0;
		}else{
			if(a[l]-a1<a[r]-a2){
				a2+=a[l];
				if(s[l]!=s[r]){
					mi+=a[l]-a1;
				}
				a1=0;
				l++;
			}else{
				if(a[l]-a1>a[r]-a2){
					a1+=a[r];
					if(s[l]!=s[r]){
						mi+=a[r]-a2;
					}
					a2=0;
					r--;
				}
			}
		}
	}
	cout<<mi;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
OWO，我的样例过了！！ 
不得不说，我的码风好xx。 
*/
