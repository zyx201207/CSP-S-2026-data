#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
char b[200010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int h=0;
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		h+=a[i];
	} 

	int js=0;
	int j=n;
	for(int i=1;i<j;){
		if(b[i]==b[j]){
			if(a[i]>a[j]){
			
			a[i]-=a[j];
			j--;
			}else if(a[i]<a[j]){
			
				a[j]-=a[i];
					i++;
			}else{
				i++,j--;
			}
		}else{
			if(a[i]>a[j]){
			js+=a[j];
			a[i]-=a[j];
			j--;
			}else if(a[i]<a[j]){
				js+=a[i];
			
				a[j]-=a[i];
				i++;
			}else{
				js+=a[i];
				i++,j--;
			}
		}
	}
	cout<<js;
	return 0;
}

