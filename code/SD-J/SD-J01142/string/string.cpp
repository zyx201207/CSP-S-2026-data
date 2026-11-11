#include<iostream>//hi 100
#include<cstdio>
using namespace std;
int n,l,r;
long long ans;
struct node{
	int p;
	char c;
}a[200005];
void fun(){
	if(a[l].p>a[r].p){
		a[l].p=a[l].p-a[r].p;
		r--;
	}
	else if(a[l].p<a[r].p){
		a[r].p=a[r].p-a[l].p;
		l++;
	}
	else{
		l++,r--;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].p>>a[i].c;
	}
	l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			fun();
		}
		else{
			ans=ans+min(a[l].p,a[r].p);
			fun();
		}
	}
	cout<<ans;
	return 0;
}
