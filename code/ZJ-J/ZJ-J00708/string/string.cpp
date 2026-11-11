#include<bits/stdc++.h>
using namespace std;
const int mn = 1e5+9;
int n,tot=0;
long long ans;
struct node{
	long long x;
	char c;
}a[mn],b[mn];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> b[i].x >> b[i].c;
	}
	for(int i=1;i<=n;i++){
		if(a[tot].c!=b[i].c){
			a[++tot].x = b[i].x;
			a[tot].c = b[i].c;
		}
		else{
			a[tot].x+=b[i].x;
		}
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].x==a[r].x){
			if(a[l].c==a[r].c){
				l++;
				r--;
			}
			else{
				ans+=a[l].x;
				l++;
				r--;
			}
		}
		else if(a[l].x<a[r].x){
			if(a[l].c==a[r].c){
				a[r].x-=a[l].x;
				l++;
			}
			else{
				ans+=a[l].x;
				a[r].x-=a[l].x;
				l++;
			}
		}
		else{
			if(a[l].c==a[r].c){
				a[l].x-=a[r].x;
				r--;
			}
			else{
				ans+=a[r].x;
				a[l].x-=a[r].x;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
