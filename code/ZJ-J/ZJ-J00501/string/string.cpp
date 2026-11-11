#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char b;
};
int n;
node a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
	}
	long long ans=0;
	for(int i=1,j=n;i<j;){
		if(a[i].a>a[j].a){
			if(a[i].b!=a[j].b){
				ans+=a[j].a;
			}
			a[i].a-=a[j].a;
			j--;
		}else if(a[i].a<a[j].a){
			if(a[i].b!=a[j].b){
				ans+=a[i].a;
			}
			a[j].a-=a[i].a;
			i++;
		}else{
			if(a[i].b!=a[j].b){
				ans+=a[i].a;
			}
			i++,j--;
		}
	}
	cout<<ans;
	return 0;
}
