#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,cnt,sum;
struct node{
	char s;
	long long x;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].s;
	}long long l=1,r=n;
	while(l<r){
		if(a[l].s!=a[r].s){
			sum+=min(a[l].x,a[r].x);
			if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				r--;
			}else if(a[l].x<a[r].x){
				a[r].x-=a[l].x;
				l++;
			}else{
				r--;
				l++;
			}
		}else{
			if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				r--;
			}else if(a[l].x<a[r].x){
				a[r].x-=a[l].x;
				l++;
			}else{
				r--;
				l++;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
