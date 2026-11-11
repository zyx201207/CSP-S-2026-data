#include<bits/stdc++.h>
using namespace std;
struct node{
	long long b;
	char s;
}a[200005];
long long sum=0;
long long R,L;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	R=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].b>>a[i].s;
	}
	while(L<=R){
		if(a[L].b-a[R].b>0){
			if(a[L].s!=a[R].s){
				sum+=a[R].b;
				a[L].b-=a[R].b;
				R--;
			}
			else{
				a[L].b-=a[R].b;
				R--;
			}
		}else if(a[L].b-a[R].b<0){
			if(a[L].s!=a[R].s){
				sum+=a[L].b;
				a[R].b-=a[L].b;
				L++;
			}
			else{
				a[R].b-=a[L].b;
				L++;
			}
		}else{
			if(a[L].s!=a[R].s){
				sum+=a[L].b;
				R--;
				L++;
			}
			else{
				R--;
				L++;
			}
		}
	}
	cout<<sum;
} 
