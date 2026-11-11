#include <bits/stdc++.h>

using namespace std;
int n;
struct czx{
	int z;
	char f;
}a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].z>>a[i].f;
	}
	int t=1,w=n;
	long long ans=0;
	while(1){
		if(a[t].z>a[w].z){
			if(a[t].f!=a[w].f){
				ans+=a[w].z;
			}
			a[t].z-=a[w].z;
			w--;
		}
		else{
			if(a[t].f!=a[w].f){
				ans+=a[t].z;
			}
			a[w].z-=a[t].z;
			t++;
		}
		if(w==t){
			break;
		}
	}
	cout<<ans;
	return 0;
}
