#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N = 2e5+5;
int k,t,cnt,t1=1,t2,o,mn;
char cc,l;
struct S{
	int x;
	char y;
	int id;
}tt;
S a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		k++;
		cin>>a[k].x>>a[k].y;
		if(a[k].y==l){
			a[k-1].x+=a[k].x;
			k--;
		}else{
			l=a[k].y;
		}
	}
	t2=k;
	while(t1<=t2){
		if(tt.id==t1){
			cnt+=tt.x;
			a[t1].x++;
		}else if(tt.id==t2){
			cnt+=tt.x;
			a[t2].x++;
		}
		if(a[t1].x<a[t2].x){
			o=t2-1;
			mn=a[t1].x;
			cc=a[t2].y;
		}else{
			o=t1+1;
			mn=a[t2].x;
			cc=a[t1].y;
		}
		if(a[t1].y!=a[t2].y){
			cnt+=mn;
			tt.x=abs(a[t1].x-a[t2].x);
			tt.y=cc;
			tt.id=o;
		}else{
			tt.x=abs(a[t1].x-a[t2].x);
			tt.y=cc;
			tt.id=o;
		}
		t1++;
		t2--;
	}
	cout<<cnt;
	return 0;
}

