#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct stu{
	ll num;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	int l=1,r=n;
	ll sum=0;
	while(l<r){
		if(a[l].num>a[r].num){
			if(a[l].c!=a[r].c)sum+=a[r].num;
			a[l].num-=a[r].num;
			r--;
		}else if(a[l].num<a[r].num){
			if(a[l].c!=a[r].c)sum+=a[l].num;
			a[r].num-=a[l].num;
			l++;
			
		}else {
			if(a[l].c!=a[r].c)sum+=a[r].num;
			l++;
			r--;
		}
	}
	cout<<sum;
	return 0;
}
