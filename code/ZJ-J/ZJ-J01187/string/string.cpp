#include<bits/stdc++.h>
using namespace std;
long long sum,a[200005],pre,pfx;
int n,r;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1;
	pre=a[l];
	pfx=a[r];
	while(l<r){
		if(c[l]==c[r]){
			if(pre>pfx){
				pre-=pfx;
				r--;
				pfx=a[r];
			}else if(pre<pfx){
				pfx-=pre;
				l++;
				pre=a[l];
			}else{
				l++;r--;
				pre=a[l];pfx=a[r];
			}
		}else{
			if(pre>pfx){
				pre-=pfx;
				r--;sum+=pfx;
				pfx=a[r];
			}else if(pre<pfx){
				pfx-=pre;
				l++;sum+=pre;
				pre=a[l];
			}else{
				l++;r--;
				sum+=pre;
				pre=a[l];pfx=a[r];
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
