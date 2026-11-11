#include<bits/stdc++.h>
using namespace std;
struct{
	int gs;
	char nl;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].gs >>a[i].nl;
	int l=1,r=n;
	long long sum=0;
	while(l<r){ 
		int x=a[l].gs,xx=a[r].gs;
		int y=a[l].nl,yy=a[r].nl;
		if(y==yy){
			if(x>xx){
				a[l].gs-=xx;
				r--;
			}
			else if(x<xx){
				a[r].gs-=x;
				l++;
			}
			else{
				l++;
				r--;
			}
		}else{
			if(x>xx){
				a[l].gs-=xx;
				r--;
				sum+=xx;
			}
			else if(x<xx){
				a[r].gs-=x;
				l++;
				sum+=x;
			}
			else{
				l++;
				sum+=xx;
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
}
