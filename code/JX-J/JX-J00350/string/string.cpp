#include<bits/stdc++.h>
using namespace std;
struct node{
	long long g;
	char s;
}a[200005];
long long sum;
int n;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].g>>a[i].s;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].s!=a[r].s){
			if(a[l].g==a[r].g){
				sum+=a[l].g;
				l++,r--;
			}else if(a[l].g<a[r].g){
				sum+=a[l].g;
				a[r].g-=a[l].g;
				l++;
			}else{
				sum+=a[r].g;
				a[l].g-=a[r].g;
				r--;
			}
		}else{
			if(a[l].g==a[r].g){
				l++,r--;
			}else if(a[l].g<a[r].g){
				a[r].g-=a[r].g;
				l++;
			}else{
				a[l].g-=a[r].g;
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
}
