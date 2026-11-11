#include<bits/stdc++.h>
using namespace std;
struct unm{long long a;char b;}a[200005];
int n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b;
	for(int i=1,j=n;i<j;){
		if(a[i].b==a[j].b){
			if(a[i].a>a[j].a){
				a[i].a-=a[j].a;j--;
			}else if(a[i].a<a[j].a){
				a[j].a-=a[i].a;i++;
			}else{i++,j--;}
		}else{
			if(a[i].a>a[j].a){
				ans+=a[j].a;a[i].a-=a[j].a;j--;
			}else if(a[i].a<a[j].a){
				ans+=a[i].a;a[j].a-=a[i].a;i++;
			}else{ans+=a[j].a;i++,j--;}
		}	
	}
	cout<<ans;
	return 0;
}
