#include<iostream>
#include<cmath>
using namespace std;
struct node{
	int q;
	string b;
}a[500005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int cnt;
	for(int i=1;i<=n;i++){
		cin>>a[i].q>>a[i].b;
		cnt+=a[i].q;
	}
	int l=1;
	int r=n;
	int ans=0;
	while(l<=r){
		if(a[l].b==a[r].b){
			if(a[l].q>a[r].q){
				a[l].q-=a[r].q;
				r--;
			}else if(a[l].q<a[r].q){
				a[r].q-=a[l].q;
				l++;
			}else if(a[l].q==a[r].q){
				l++;
				r--;
			}
		}else{
			int cnt=min(a[l].q,a[r].q);
			ans+=cnt;
			if(a[l].q>a[r].q){
				a[l].q-=a[r].q;
				r--;
			}else if(a[l].q<a[r].q){
				a[r].q-=a[l].q;
				l++;
			}else if(a[l].q==a[r].q){
				l++;
				r--;
			}
		}
	}
	cout<<ans;
} 
