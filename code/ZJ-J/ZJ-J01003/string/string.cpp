#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,lh=0,top=0,tep=0,maxx=-0x3f3f3f3f3f3f3f3f;
char lc='\0';
struct add{
	int s;
	char z;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int h;
		char c;
		scanf("%d",&h);
		cin>>c;
		if(c==lc){
			lh+=h;
		}
		else{
			top++;
			a[top].s=lh;
			a[top].z=lc;
			lh=h;
			lc=c;
		}
	}
	for(int i=1;i<=top;i++){
		maxx=max(maxx,a[i].s);
	}
	cout<<maxx;
	return 0;
} 

