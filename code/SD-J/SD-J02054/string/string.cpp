#include<bits/stdc++.h>
using namespace std;
int n;
long long s;
struct str_{
	long long num;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].c;
	int l=1,r=n;
	while(l!=r){
		if(a[l].num<a[r].num){
			a[r].num-=a[l].num;
			if(a[l].c!=a[r].c) s+=a[l].num;
			a[l].num=0;
			l++;
		}
		else{
			a[l].num-=a[r].num;
			if(a[l].c!=a[r].c) s+=a[r].num;
			a[r].num=0;
			r--;	
		}
	}
	cout<<s;
	return 0;
}
