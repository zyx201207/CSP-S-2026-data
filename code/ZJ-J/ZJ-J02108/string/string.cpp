#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
int l,r,l1,r1,x;
long long sum;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin.tie(0),cout.tie(0);
//	freopen("string6.in","r",stdin);
//	freopen("ans6.out","w",stdout);
    cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>c[i];
	}
	l=1,r=a[n],l1=1,r1=n;
	while(1){
		if(l>a[l1]){
			l=1;
			l1++;
		}
		if(r<1){
			r=a[r1-1];
			r1--;
		}		
		if((l1==r1&&l>=r)||l1>r1){
			cout<<sum;
			return 0;
		}
		if(c[l1]!=c[r1]){
			x=min(r1,a[l1]-l++);
			sum+=x;
			l+=x;
			r-=x;
		}else{
			x=min(r1,a[l1]-l++);
			l+=x;
			r-=x;
		}
	}
	return 0;
}
