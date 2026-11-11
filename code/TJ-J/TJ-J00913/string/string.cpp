#include <bits/stdc++.h>
using namespace std;
int n;
long long s;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,l=n;
	while(i<=l){
		if(c[i]==c[l]){
			if(a[i]>a[l]){
				a[i]-=a[l];
				l--;
			}
			else if(a[i]<a[l]){
				a[l]-=a[i];
				i++;
			}
			else l--,i++;
		}
		else{
			if(a[i]>a[l]){
				s+=a[l];
				a[i]-=a[l];
				l--;
			}
			else if(a[i]<a[l]){
				s+=a[i];
				a[l]-=a[i];
				i++;
			}
			else{
				s+=a[i];
				l--,i++;
			}
		}
	}
	cout<<s;
	return 0;
}
