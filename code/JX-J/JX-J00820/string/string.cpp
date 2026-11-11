#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],l=1,r,m,t,b[200005],ans,fr,ba,j;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		b[i]=a[i]+b[i-1];
	}
	r=n;
	while (l<=r){

		m = (l+r)/2;
		if (b[m] > b[n]-b[m]){
			r=m-1;
		}else{
			l=m+1;
			ans=m;
		}
	}
	j=n;
	fr=a[1];
	ba=a[n];
	for (int i = 1;i <= ans;){
		if (c[i] != c[j]){
			if (fr > ba){
				fr-=ba;
				t+=ba;
				j--;
				ba=a[j];
			}else if(fr < ba){
				ba-=fr;
				t+=fr;
				i++;
				fr=a[i];
			}else{
				t+=ba;
				i++;
				j--;
				ba=a[j];
				fr=a[i];
			}
		}else if (fr > ba){
				fr-=ba;
				j--;
				ba=a[j];
			}else if(fr < ba){
				ba-=fr;
				i++;
				fr=a[i];
			}else{
				i++;
				j--;
				ba=a[j];
				fr=a[i];
			}
		
		
		if (j<=ans){
			break;
		}
	}
	cout << t;
	return 0;
}
