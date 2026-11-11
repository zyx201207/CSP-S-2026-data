#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct{
	int a;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	for(int i=1,j=n;i<=j;){
		if(a[i].c!=a[j].c){
			if(a[i].a>=a[j].a){
				a[i].a-=a[j].a;
				ans+=a[j].a;
				a[j].a=0;
				
			}else{
				a[j].a-=a[i].a;
				ans+=a[i].a;
				a[i].a=0;
				
			}
		}else{
			if(a[i].a>=a[j].a){
				a[i].a-=a[j].a;
				a[j].a=0;
			}else{
				a[j].a-=a[i].a;
				a[i].a=0;
			}
		}
		if(a[i].a<=0){
			i++;
		}
		if(a[j].a<=0){
			j--;
		}
	}
	cout<<ans;
	return 0;
}
