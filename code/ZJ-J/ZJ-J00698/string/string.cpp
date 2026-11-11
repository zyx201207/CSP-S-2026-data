#include<bits/stdc++.h>
using namespace std;
long long n,sum;
struct node{
	long long m;
	char s;
}a[100005];
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].s;
	}
	long long l=1,r=n;
	while(l<r){
		if(a[l].s==a[r].s){
			if(a[l].m>a[r].m)a[l].m-=a[r].m,r--;
			else if(a[l].m<a[r].m)a[r].m-=a[l].m,l++;
			else l++,r--;
		}
		else {
			sum+=min(a[l].m,a[r].m);
			if(a[l].m>a[r].m)a[l].m-=a[r].m,r--;
			else if(a[l].m<a[r].m)a[r].m-=a[l].m,l++;
			else l++,r--;
		}
		
	}
	cout<<sum;
	return 0;
}
