#include<bits/stdc++.h>
using namespace std;
long long a[200010],ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n,al=a[1],ar=a[n];
	while(l<r){
		if(c[l]!=c[r]){
			if(al>ar){
				ans+=ar;
				al-=ar;
				ar=a[--r];
			}else if(al==ar){
				ans+=ar;
				al=a[++l];
				ar=a[--r];
			}else{
				ans+=al;
				ar-=al;
				al=a[++l];
			}
		}else{
			if(al>ar){
				al-=ar;
				ar=a[--r];
			}else if(al==ar){
				al=a[++l];
				ar=a[--r];
			}else{
				ar-=al;
				al=a[++l];
			}
		}
	}
	cout<<ans;
	return 0;
}
