#include<bits/stdc++.h>
using namespace std;
int ans,b,v;
char z;
struct g{
	int x;
	char a;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	b=1;
	for(int i=1;i<=n;i++){
		cin >> a[b].x >> a[b].a;
		if(a[b].a==a[b-1].a){
			a[b-1].x+=a[b].x;
			b--;
		}
		b++;
	}
	for(int i=1;i<b;i++){
		cout << a[i].x << ' ' <<  a[i].a << "\n";
	}
	for(int i=1;i<=b/2;i++){
		if(a[i].a!=a[b-i].a){
			ans+=min(a[b-i].x,a[i].x);
			v=abs(a[i].x-a[b-i].x);
			if(a[i].x>a[b-i].x){
				z=a[i].a;
				if(a[b-i-1].a!=z){
					ans+=min(a[b-i-1].x,v);
					v=abs(v-a[b-i-1].x);
				}
				
			}
			else{
				z=a[b-i].a;
				if(a[i+1].a!=z){
					ans+=min(a[i+1].x,v);
					v=abs(v-a[i+1].x);
				}
			}
		}
	}
	cout << ans;
	return 0;
} 
